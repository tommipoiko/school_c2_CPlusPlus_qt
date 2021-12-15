#include "cards.hh"

using namespace std;

Cards::Cards(): top_(nullptr), bottom_(nullptr) {
}

void Cards::add(int id)
{
    Card_data* new_item = new Card_data{id, nullptr, nullptr};

    if ( top_ == nullptr ) {
        top_ = new_item;
        bottom_ = new_item;
    } else {
        new_item->next = top_;
        top_->previous = new_item;
        top_ = new_item;
    }
}

void Cards::print_from_top_to_bottom(std::ostream &s)
{
    Card_data* card_to_be_printed = top_;
    int running_number = 1;

    while (card_to_be_printed != nullptr) {
        s << running_number << ": " << card_to_be_printed->data << endl;
        ++running_number;
        card_to_be_printed = card_to_be_printed->next;
    }
}

bool Cards::remove(int &id)
{
    if (top_ == nullptr) {
        return false;
    } else {
        Card_data* card_to_be_deleted = top_;
        id = card_to_be_deleted->data;
        top_ = top_->next;
        delete card_to_be_deleted;
        return true;
    }
}

bool Cards::bottom_to_top()
{
    if (top_ == nullptr || top_->next == nullptr) {
        return false;
    } else {
        Card_data* second_last = top_;
        Card_data* third_last = top_;
        Card_data* new_top = bottom_;

        while (second_last->next != bottom_) {
            second_last = second_last->next;
        }
        while (third_last->next->next != bottom_) {
            third_last = third_last->next;
        }

        new_top->next = top_;
        new_top->previous = nullptr;
        top_->previous = new_top;
        top_ = new_top;
        bottom_ = second_last;
        second_last->next = nullptr;
        second_last->previous = third_last;

        return true;
    }
}

bool Cards::top_to_bottom()
{
    if (top_ == nullptr || top_->next == nullptr) {
        return false;
    } else {
        Card_data* card_to_be_moved = top_;
        Card_data* old_bottom = bottom_;
        top_ = top_->next;
        top_->previous = nullptr;
        old_bottom->next = card_to_be_moved;
        bottom_ = card_to_be_moved;
        bottom_->next = nullptr;
        bottom_->previous = old_bottom;

        return true;
    }
}

void Cards::print_from_bottom_to_top(std::ostream &s)
{
    int running_number = 1;
    Card_data* card_to_be_printed = bottom_;

    while (card_to_be_printed != nullptr) {
        s << running_number << ": " << card_to_be_printed->data << endl;
        ++running_number;
        card_to_be_printed = card_to_be_printed->previous;
    }
}

Cards::~Cards()
{
    while ( top_ != nullptr ) {
       Card_data* item_to_be_released = top_;
       top_ = top_->next;

       delete item_to_be_released;
    }
}
