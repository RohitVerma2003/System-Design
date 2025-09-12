#include "ParkingTicket.hpp"
#include <string>
#include <iostream>
using namespace std;

ParkingTicket::ParkingTicket(string id, Vehicle vehicle, ParkingSpot spot, int time, string gate) : id(id), vehicle(vehicle), spot(spot), entry_time(time), entry_gate(gate) {}

string ParkingTicket::get_entry_gate(){
    return this->entry_gate;
}

int ParkingTicket::get_entry_time(){
    return this->entry_time;
}

ParkingSpot ParkingTicket::get_parking_spot(){
    return this->spot;
}

Vehicle ParkingTicket::get_vehicle(){
    return this->vehicle; 
}

void ParkingTicket::display_info(){
    cout<<"=====Parking Ticket====="<<endl;
    cout<<"id: "<<this->id<<endl;
    this->spot.display_info();
    cout<<"===================="<<endl;
}