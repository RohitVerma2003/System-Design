#include "../headers/Card.hpp"

Card::Card(std::string user_id , std::string account_number , std::string pin): user_id(user_id) , account_number(account_number) , pin(pin){
    int num = std::rand() % 100000;
    this->card_number = std::to_string(num);
}

std::string Card::get_card_number(){return this->card_number;}
std::string Card::get_account_number(){return this->account_number;}
std::string Card::get_user_id(){return this->user_id;}

bool Card::validate_pin(std::string pin){return this->pin == pin;}