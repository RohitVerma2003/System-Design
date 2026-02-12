#ifndef PARKINGLOT_HPP
#define PARKINGLOT_HPP

#include <unordered_map>
#include <string>
#include <iostream>
#include "Floor.hpp"
#include "Ticket.hpp"
#include "User.hpp"
#include "IParkingSpotFinder.hpp"
#include "IPaymentProcessor.hpp"
#include "../enum.hpp"
using namespace std;
#pragma once


class ParkingLot{
private:
    unordered_map<int , Floor*> floors;
    unordered_map<string , Ticket*> tickets;
    IParkingSpotFinder* spotFinder;
    IPaymentProcessor* paymentProcessor;

public:
    ParkingLot(IParkingSpotFinder* spotFinder, IPaymentProcessor* paymentProcessor);
    void setFloor(Floor* floor);
    void setTicket(Ticket* ticket);

    bool isSpotAvailable(VehicleType type);
    void parkVehicle(User* user);
    void unparkVehicle(User* user);
};


#endif