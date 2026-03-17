#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "./User.hpp"
#include <random>

class Account{
private:
    float amount;
    std::string account_number , user_id;

public:
    Account(std::string user_id);

    float get_amount();
    std::string get_account_number();
    void deposit_amount(float amount);
    void withdraw_amount(float amount);
};

#endif