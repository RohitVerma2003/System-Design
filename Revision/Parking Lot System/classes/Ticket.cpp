#include "../headers/Ticket.hpp"
#include <random>
#include <iostream>
using namespace std;

Ticket::Ticket(ParkingSpot* spot , string userid, string timings, IPaymentProcessor* paymentProcessor): ticketId(""), userId(userid), timings(timings), spot(spot){
    cout << "[Ticket] Creating ticket for user: " << userid << " at spot: " << spot->getSpotId() << endl;
    this->payment = paymentProcessor->processPayment(100 , spot->getSpotId() , userid , timings);

    int random = rand() % 100000;
    this->ticketId = to_string(random);
    cout << "[Ticket] Ticket ID generated: " << this->ticketId << endl;
}

ParkingSpot* Ticket::getSpot() const{return this->spot;}
string Ticket::getUserId() const{return this->userId;}
Payment* Ticket::getPayment() const{return this->payment;}
string Ticket::getTimings() const{return this->timings;}
string Ticket::getTicketId() const{return this->ticketId;}