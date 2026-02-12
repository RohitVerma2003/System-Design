#ifndef PARKINGSPOT_HPP
#define PARKINGSPOT_HPP

#include <string>
#include "../enum.hpp"
#include "Vehicle.hpp"
using namespace std;
#pragma once

class ParkingSpot{
private:
    string spotId;
    VehicleType vechicleType;
    Vehicle* occupiedBy;
    bool occupied;
    int floor;

public:
    ParkingSpot(string spotid, VehicleType type , int floor);

    string getSpotId() const;
    VehicleType getVehicleType() const;
    void setIsOccupied(bool value);
    bool isOccupied() const;
    Vehicle* getOccupiedBy() const;
    void setOccupiedBy(Vehicle* vehicle);
    int getFloor() const;
};

#endif