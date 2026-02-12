#ifndef IPAYMENTPROCESSOR_HPP
#define IPAYMENTPROCESSOR_HPP

#include <string>
#include "Payment.hpp"
using namespace std;

class IPaymentProcessor {
public:
    virtual ~IPaymentProcessor() {}
    virtual Payment* processPayment(float amount, string spotId, string userId, string timing) = 0;
};

#endif
