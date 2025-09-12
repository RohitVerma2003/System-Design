#include "PaymentSystem.hpp"
#include <string>
#include <iostream>
using namespace std;

PaymentSystem::PaymentSystem(string id , ParkingTicket* ticket): id(id) , parking_ticket(ticket) , status(false){}

void PaymentSystem::calculate_payment(int exit_time , double rate){
    this->occupancy_time = exit_time - this->parking_ticket->entry_time;
    this->charge = rate * this->occupancy_time;
}

bool PaymentSystem::make_payment(PaymentType type){
    if(this->status) return true;
    this->payment_type = type;
    this->display_info();
    this->status = true;
    return true;
}

void PaymentSystem::display_info(){
    cout<<"=====Payment Info====="<<endl;
    cout<<"id: "<<this->id<<endl;
    cout<<"Payment Method: ";

    switch(this->payment_type){
        case PaymentType::CARD:
            cout<<"Card"<<endl;
            break;
        case PaymentType::CASH:
            cout<<"Cash"<<endl;
            break;
    }

    cout<<"Payment Status: Done"<<endl;
    cout<<"Ticket Info: "<<endl;
    this->parking_ticket->display_info();
    cout<<"===================="<<endl;
}