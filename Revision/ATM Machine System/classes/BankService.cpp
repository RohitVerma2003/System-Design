#include "../headers/BankService.hpp"

BankService::BankService() {}

BankService &BankService::get_instance(){
    static BankService instance;
    return instance;
}

Account* BankService::create_account(User *user)
{
    this->users[user->get_email()] = user;
    Account* account = new Account(user->get_email());

    this->accounts[account->get_account_number()] = account;
    return account;
}

Card* BankService::create_card(std::string user_id , std::string account_number , std::string pin){
    Card* card = new Card(user_id , account_number , pin);
    this->cards[card->get_card_number()] = card;

    return card;
}

Account *BankService::get_account(std::string account_number){
    return this->accounts[account_number];
}

void BankService::deposit_amount(std::string account_number , float amount){
    Account* account = this->accounts[account_number];

    if(!account){
        std::cout<<"Account does not exist"<<std::endl;
        return;
    }

    account->deposit_amount(amount);
}

void BankService::withdraw_amount(std::string account_number, float amount){
    Account* account = this->accounts[account_number];

    if(!account){
        std::cout<<"Account does not exist"<<std::endl;
        return;
    }

    account->withdraw_amount(amount);
}

bool BankService::validate_card_pin(std::string card_id, std::string pin){
    Card* card = this->cards[card_id];

    if(!card){
        std::cout<<"Card does not exist"<<std::endl;
        return false;
    }

    return card->validate_pin(pin);
}