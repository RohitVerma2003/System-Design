#include <string>
using namespace std;
#pragma once

enum class VehicleType{
    COMPACT , HANDICAPPED , LARGE , SMALL
};

class Vehicle{
private:
    string number_plate;
    VehicleType vehicle_type;
public:
    Vehicle(string plate , VehicleType type);
    string get_number_plate();
    VehicleType get_vehicle_type();
    void vehicle_info();

};