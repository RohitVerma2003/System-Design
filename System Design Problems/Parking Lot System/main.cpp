#include "ParkingLot.hpp"
#include <iostream>
using namespace std;

int main(){
    vector<string> entry_gates = {"A" , "B"};
    vector<string> exit_gates = {"A" , "B"};

    ParkingLot* parking_lot = ParkingLot::get_instance(40000 , 50 , entry_gates , exit_gates);

    Vehicle car("UP80-7777" , VehicleType::COMPACT);
    Vehicle bike("UP80-7035" , VehicleType::SMALL);
    Vehicle truck("DL33-5382" , VehicleType::LARGE);
    Vehicle handi("MH67-8742" , VehicleType::HANDICAPPED);

    ParkingTicket* ticket1 = parking_lot->park_vehicle(car , 1 , "A");
    ParkingTicket* ticket2 = parking_lot->park_vehicle(bike , 1 , "B");
    ParkingTicket* ticket3 = parking_lot->park_vehicle(truck , 1 , "B");
    ParkingTicket* ticket4 = parking_lot->park_vehicle(handi , 1 , "A");

    parking_lot->unpark_vehicle(ticket1 , 3 , "B" , PaymentType::CARD);
    parking_lot->unpark_vehicle(ticket2 , 5 , "A" , PaymentType::CARD);
    parking_lot->unpark_vehicle(ticket3 , 7 , "B" , PaymentType::CASH);
    parking_lot->unpark_vehicle(ticket4 , 4 , "A" , PaymentType::CARD);

    delete parking_lot;
    delete ticket1;
    delete ticket2;
    delete ticket3;
    delete ticket4;
    return 0;
}