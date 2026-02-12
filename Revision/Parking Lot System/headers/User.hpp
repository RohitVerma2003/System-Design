#ifndef USER_HPP
#define USER_HPP


#include <string>
#include "Vehicle.hpp"
#include "Ticket.hpp"
using namespace std;
#pragma once

class User{
private:
    string userId, name;
    Vehicle* vehicle;
    Ticket* ticket;

    public:
    User(string name, Vehicle* vehicle);
    
    string getName() const;
    Vehicle* getVehicle() const;
    Ticket* getTicket() const;
    void setTicket(Ticket* ticket);
};



#endif