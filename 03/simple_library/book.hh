#ifndef BOOK_HH
#define BOOK_HH
#include "date.hh"
#include <iostream>

#include <string>

class Book
{
public:
    Book();
    Book(std::string author, std::string book_name);
    void print() const;
    void loan(Date today);
    void renew();
    void give_back();

private:
    std::string author_;
    std::string book_name_;
    bool is_loaned_;
    Date date_loaned_;
    Date to_be_returned_;

};

#endif // BOOK_HH
