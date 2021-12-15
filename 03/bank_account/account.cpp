#include "account.hh"
#include <iostream>

Account::Account(const std::string& owner, bool has_credit):
    owner_(owner), has_credit_(has_credit)
{
    generate_iban();
}

void Account::print() const
{
    std::cout << owner_ << " : " << iban_ << " : " << amount_money_ << " euros" << std::endl;
}

void Account::set_credit_limit(int credit_amount)
{
    if (has_credit_ == true) {
        int credit_amount_ = 0;
        credit_amount_ += credit_amount;
    } else {
        std::cout << "Cannot set credit limit: the account has no credit card" << std::endl;
    }
}

void Account::save_money(int amount_money)
{
    amount_money_ += amount_money;
}

void Account::take_money(int money_taken)
{
    if (amount_money_ >= money_taken) {
        amount_money_ -= money_taken;
        std::cout << money_taken << " euros taken: new balance of " << iban_ << " is " << amount_money_ << " euros" << std::endl;
    } else if (has_credit_ == true) {
        if (0 - amount_money_ < credit_amount_) {
            amount_money_ -= money_taken;
            std::cout << money_taken << " euros taken: new balance of " << iban_ << " is " << amount_money_ << " euros" << std::endl;
        } else {
            std::cout << "Cannot take money: credit limit overflow" << std::endl;
        }
    } else {
        std::cout << "Cannot take money: balance underflow" << std::endl;
    }
}

void Account::transfer_to(Account& other_account, int money_transferred)
{
    if (amount_money_ >= money_transferred) {
        //other_account.save_money(money_transferred);
        other_account.amount_money_ += money_transferred;
        amount_money_ -= money_transferred;
        std::cout << money_transferred << " euros taken: new balance of " << iban_ << " is " << amount_money_ << " euros" << std::endl;
    } else if (has_credit_ == true) {
        if (0 - amount_money_ < credit_amount_) {
            //other_account.save_money(money_transferred);
            other_account.amount_money_ += money_transferred;
            amount_money_ -= money_transferred;
            std::cout << money_transferred << " euros taken: new balance of " << iban_ << " is " << amount_money_ << " euros" << std::endl;
        } else {
            std::cout << "Cannot take money: credit limit overflow" << std::endl;
        }
    } else {
        std::cout << "Cannot take money: balance underflow" << std::endl;
    }
}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
    amount_money_ = 0;
}
