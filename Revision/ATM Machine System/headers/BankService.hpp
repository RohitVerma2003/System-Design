#ifndef BANK_SERVICE_HPP
#define BANK_SERVICE_HPP

#include "./Account.hpp"
#include "./Card.hpp"
#include "./User.hpp"
#include <unordered_map>
#include <iostream>

class BankService{
private:
    std::unordered_map<std::string , User*> users;
    std::unordered_map<std::string , Account*> accounts;
    std::unordered_map<std::string , Card*> cards;

    BankService();
    BankService(const BankService&) = delete;
    BankService& operator=(const BankService&) = delete;
public:
    static BankService& get_instance();

    Account* create_account(User* user);
    Card* create_card(std::string user_id , std::string account_number , std::string pin);
    Account* get_account(std::string account_number);

    void deposit_amount(std::string account_number , float amount);
    void withdraw_amount(std::string account_number , float amount);

    bool validate_card_pin(std::string card_id , std::string pin);
};

#endif