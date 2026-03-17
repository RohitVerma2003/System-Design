#include "../headers/Account.hpp"

Account::Account(std::string user_id): user_id(user_id){
    int num = rand() % 100000;
    this->account_number = std::to_string(num);
    this->amount = 0;
}

float Account::get_amount(){return this->amount;}

std::string Account::get_account_number(){return this->account_number;}

void Account::deposit_amount(float amount){this->amount += amount;}

void Account::withdraw_amount(float amount){
    if(this->amount < amount) return;
    this->amount -= amount;
}