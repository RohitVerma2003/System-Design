#include "../headers/Payment.hpp"
#include <iostream>
#include <random>
using namespace std;

Payment::Payment(float amount, string spotid, string userid, string timing) : paymentId(""), parkingSpotId(spotid), userId(userid), timings(timing), amount(amount){
    int random = rand() % 100000;
    this->paymentId = to_string(random);
    cout << "[Payment] Payment record created with ID: " << this->paymentId << endl;
}

string Payment::getPaymentId() const {return this->paymentId;}
string Payment::getTime() const {return this->timings;}
float Payment::getAmount() const {return this->amount;}
string Payment::getSpotId() const {return this->parkingSpotId;}