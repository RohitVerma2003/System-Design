#include <map>
#include <string>
#include <vector>
#include <mutex>
#include <iostream>
#include "ParkingLot.hpp"
using namespace std;

ParkingLot* ParkingLot::instance = nullptr;
mutex ParkingLot::mtx;

ParkingLot* ParkingLot::get_instance(int size , double rates , vector<string>& entry , vector<string>& exit){
    if(instance == nullptr){
        lock_guard<mutex> lock(mtx);
        if(instance == nullptr) instance = new ParkingLot(size , rates , entry , exit);
    }
    return instance;
}

ParkingLot::ParkingLot(int size , double rates , vector<string>& entry , vector<string>& exit){
    this->total_size = size;
    this->per_hour_rates = rates;
    this->entry_gates = entry;
    this->exit_gates = exit;

    int space = this->total_size / 4;
    this->compact_space = this->handicapped_space = this->large_space = this->small_space = space;
}

string ParkingLot::find_spots(VehicleType vehicle_type){
    int search_space = 0;
    string type;
    switch(vehicle_type){
        case VehicleType::COMPACT: 
            search_space = this->compact_space;
            type = "COMPACT";
            break;
        case VehicleType::LARGE: 
            search_space = this->large_space;
            type = "LARGE";
            break;
        case VehicleType::SMALL: 
            search_space = this->small_space;
            type = "SMALL";
            break;
        case VehicleType::HANDICAPPED: 
            search_space = this->handicapped_space;
            type = "HANDICAPPED";
            break;
    }

    for(int i = 0 ; i < search_space ; i++){
        string id = to_string(i) + type;

        if(this->spots.find(id) != this->spots.end()){
            if(!this->spots.at(id)->get_parking_spot().get_occupancy()){
                return id;
            }
        }else{
            return id;
        }
    }

    return "";
}

ParkingTicket* ParkingLot::park_vehicle(Vehicle vehicle , int entry , string gate){
    if(this->total_size <= 0){
        cout<<"=======Not Enough Space...======="<<endl;
        return nullptr;
    }

    VehicleType vehicle_type = vehicle.get_vehicle_type();
    string spot_id = this->find_spots(vehicle_type);
    
    ParkingSpot spot(spot_id);
    spot.set_vehicle(vehicle);
    spot.set_occupancy(true);

    ParkingTicket* parking_ticket = new ParkingTicket(vehicle.get_number_plate() , vehicle , spot , entry , gate);
    this->spots.insert_or_assign(spot_id , parking_ticket);
    this->total_size--;
    
    switch(vehicle.get_vehicle_type()){
        case VehicleType::COMPACT: 
            this->compact_space--;
            break;
        case VehicleType::LARGE: 
            this->large_space--;
            break;
        case VehicleType::SMALL: 
            this->small_space--;
            break;
        case VehicleType::HANDICAPPED: 
            this->handicapped_space--;
            break;
    }

    cout<<"=====Vehicle Parked====="<<endl;
    spot.display_info();
    return parking_ticket;
}

bool ParkingLot::unpark_vehicle(ParkingTicket* parking_ticket , int exit_time , string exit_gate , PaymentType pay_type){
    ParkingSpot spot = parking_ticket->get_parking_spot();
    Vehicle vehicle = parking_ticket->get_vehicle();
    
    PaymentSystem* payment_system = new PaymentSystem(vehicle.get_number_plate() , parking_ticket);
    payment_system->calculate_payment(exit_time , this->per_hour_rates);
    bool payment_status = payment_system->make_payment(pay_type);

    if(!payment_status){
        cout<<"======PAYMENT UNSUCCESSFULL======"<<endl;
        return false;
    }
    delete payment_system;

    spot.set_occupancy(false);
    this->total_size++;

    switch(vehicle.get_vehicle_type()){
        case VehicleType::COMPACT: 
            this->compact_space++;
            break;
        case VehicleType::LARGE: 
            this->large_space++;
            break;
        case VehicleType::SMALL: 
            this->small_space++;
            break;
        case VehicleType::HANDICAPPED: 
            this->handicapped_space++;
            break;
    }

    cout<<"======Vehicle UnParked======"<<endl;
    cout<<"Exiting by gate: "<<exit_gate<<endl;
    return true;
}