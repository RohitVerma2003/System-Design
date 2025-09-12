#include "Vehicle.hpp"
#include <string>
#include <iostream>
using namespace std;

Vehicle::Vehicle(string plate , VehicleType type): number_plate(plate) , vehicle_type(type){}

string Vehicle::get_number_plate(){
    return this->number_plate;
}

VehicleType Vehicle::get_vehicle_type(){
    return this->vehicle_type;
}

void Vehicle::vehicle_info(){
    cout<<"===== Vehcile ====="<<endl;

    switch(this->get_vehicle_type()){
        case VehicleType::COMPACT: 
            cout<<"Compact Vehicle"<<endl;
            break;
        case VehicleType::LARGE: 
            cout<<"Large Vehicle"<<endl;
            break;
        case VehicleType::SMALL: 
            cout<<"Small Vehicle"<<endl;
            break;
        case VehicleType::HANDICAPPED: 
            cout<<"Handicapped Vehicle"<<endl;
            break;
    }   

    cout<<"Number Plate: "<<this->get_number_plate()<<endl;
    cout<<"===================="<<endl;
}