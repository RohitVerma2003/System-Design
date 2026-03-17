#include "../headers/User.hpp"

User::User(std::string name , std::string email): name(name) , email(email){}

std::string User::get_name(){return this->name;}
std::string User::get_email(){return this->email;}