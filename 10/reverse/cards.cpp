#include <iostream>
#include <memory>
#include "cards.hh"


Cards::Cards(): top_(nullptr), bottom_(nullptr) {
}


void Cards::add(int id) {
    std::shared_ptr<Card_data> new_card 
            = std::make_shared<Card_data>(Card_data{id, top_});
    top_ = new_card;
}

void Cards::print(std::ostream& s) {
   std::shared_ptr<Card_data> to_be_printed = top_;
   int nr = 1;

   while( to_be_printed != 0 ) {
      s << nr << ": " << to_be_printed->data << std::endl;
      to_be_printed = to_be_printed->next;
      ++nr;
   }
}

bool Cards::remove(int &id)
{
    if (top_ == nullptr) {
        return false;
    } else {
        std::shared_ptr<Card_data> del = top_;
        id = del->data;
        top_ = top_->next;
        del = nullptr;
        return true;
    }
}

void Cards::reverse()
{
    //
}
