#include "ParkingSpot.hpp"
#include <string>
#include <iostream>
using namespace std;

ParkingSpot::ParkingSpot(string id): id(id) , vehicle("", VehicleType::COMPACT){}

void ParkingSpot::set_vehicle(Vehicle vehicle){
    this->vehicle = vehicle;
}

Vehicle ParkingSpot::get_vehicle(){
    return this->vehicle;
}

void ParkingSpot::set_occupancy(bool value){
    this->is_occupied = value;
}

bool ParkingSpot::get_occupancy(){
    return this->is_occupied;
}

void ParkingSpot::display_info(){
    cout<<"===== Parking Spot ====="<<endl;
    cout<<"id: "<<this->id<<endl;
    this->vehicle.vehicle_info();
    cout<<"===================="<<endl;
}