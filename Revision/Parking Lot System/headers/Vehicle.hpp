#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include <string>
#include "../enum.hpp"
using namespace std;
#pragma once

class Vehicle{
private:
    string vehicleNumber;
    VehicleType type;

public: 
    Vehicle(string number, VehicleType type);

    string getVehicleNumber() const;
    void setVehicleType(VehicleType type);
    VehicleType getVehicleType() const;
};


#endif