#ifndef CARD_HPP
#define CARD_HPP

#include <string>
#include <random>

class Card{
private:
    std::string card_number , user_id , account_number , pin;
public:
    Card(std::string user_id , std::string account_number , std::string pin);

    std::string get_card_number();
    std::string get_user_id();
    std::string get_account_number();
    bool validate_pin(std::string pin);
};

#endif