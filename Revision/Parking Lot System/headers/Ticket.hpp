#ifndef TICKET_HPP
#define TICKET_HPP

#include <string>
#include "ParkingSpot.hpp"
#include "Payment.hpp"
#include "IPaymentProcessor.hpp"
using namespace std;
#pragma once

class Ticket{
private:
    string ticketId , userId, timings;
    ParkingSpot* spot;
    Payment* payment;

public:
    Ticket(ParkingSpot* spot , string userid, string timings, IPaymentProcessor* paymentProcessor);

    ParkingSpot* getSpot() const;
    string getUserId() const;
    Payment* getPayment() const;
    string getTimings() const;
    string getTicketId() const;
};

#endif