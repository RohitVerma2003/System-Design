#include "../headers/User.hpp"
#include <random>
#include <iostream>

User::User(string name, Vehicle* vehicle): name(name) , vehicle(vehicle), ticket(NULL){
    int random = rand() % 10000;
    this->userId = to_string(random);
    cout << "[User] Created user: " << name << " (ID: " << this->userId << ")" << endl;
}

string User::getName() const{return this->name;}
Vehicle* User::getVehicle() const{return this->vehicle;}
Ticket* User::getTicket() const{return this->ticket;}

void User::setTicket(Ticket* ticket){this->ticket = ticket;}