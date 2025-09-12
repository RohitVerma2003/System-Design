#include "Vehicle.hpp"
#include <string>
using namespace std;
#pragma once

class ParkingSpot{
private:
    string id;
    bool is_occupied;
public:
    Vehicle vehicle;

    ParkingSpot(string id);
    void set_vehicle(Vehicle vechicle);
    Vehicle get_vehicle();
    void set_occupancy(bool value);
    bool get_occupancy();

    void display_info();
};