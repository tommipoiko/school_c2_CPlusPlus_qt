#include "book.hh"
#include "date.hh"
#include <iostream>

Book::Book():
    author_(""), book_name_("")
{

}

Book::Book(std::string author, std::string book_name)
{
    author_ = author;
    book_name_ = book_name;
    is_loaned_ = false;
}

void Book::print() const
{
    std::cout << author_ << " : " << book_name_ << std::endl;
    if (is_loaned_ == true) {
        std::cout << "- loaned: ";
        date_loaned_.print();
        std::cout << "- to be returned: ";
        to_be_returned_.print();
    } else {
        std::cout << "- available" << std::endl;
    }
}

void Book::loan(Date today)
{
    if (is_loaned_ == false) {
        is_loaned_ = true;
        date_loaned_ = today;
        Date daba = today;
        daba.advance(28);
        to_be_returned_ = daba;
    } else {
        std::cout << "Already loaned: cannot be loaned" << std::endl;
    }
}

void Book::renew()
{
    if (is_loaned_ == true) {
        to_be_returned_.advance(28);
    } else {
        std::cout << "Not loaned: cannot be renewed" << std::endl;
    }
}

void Book::give_back()
{
    if (is_loaned_ == true) {
        is_loaned_ = false;
    }
}
