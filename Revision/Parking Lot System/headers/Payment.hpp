#ifndef PAYMENT_HPP
#define PAYMENT_HPP

#include <string>
using namespace std;

class Payment{
private:
    string paymentId , parkingSpotId, userId , timings;
    float amount;

public:
    Payment(float amount , string spotid , string userid , string timing);

    string getPaymentId() const;
    string getTime() const;
    string getSpotId() const;
    float getAmount() const;
};


#endif 