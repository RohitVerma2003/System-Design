#include "Vehicle.hpp"
#include "ParkingSpot.hpp"
#include <string>
using namespace std;
#pragma once

class ParkingTicket{
private:
    string id;
    Vehicle vehicle;
    ParkingSpot spot;
public:
    int entry_time;
    string entry_gate;

    ParkingTicket(string id , Vehicle vehicle , ParkingSpot spot , int time , string gate);
    int get_entry_time();
    string get_entry_gate();
    Vehicle get_vehicle();
    ParkingSpot get_parking_spot();
    void display_info();
};