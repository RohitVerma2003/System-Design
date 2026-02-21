#include "../headers/User.hpp"

User::User(string name , string email): name(name) , email(email){
    int num = rand() % 100000;
    this->id = to_string(num);
}

string User::get_name(){return this->name;}

string User::get_id(){return this->id;}

void User::set_name(string name){this->name = name;}

float User::get_score(){return 0;}