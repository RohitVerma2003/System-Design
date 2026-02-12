#include "../headers/Vehicle.hpp"
#include <iostream>

using namespace std;

Vehicle::Vehicle(string number, VehicleType type) : vehicleNumber(number), type(type) {
    cout << "[Vehicle] Created vehicle: " << number << " (Type: " << type << ")" << endl;
}

string Vehicle::getVehicleNumber() const { return this->vehicleNumber; }
VehicleType Vehicle::getVehicleType() const { return this->type; }
void Vehicle::setVehicleType(VehicleType type) { this->type = type; }