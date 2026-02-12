#ifndef PAYMENTPROCESSOR_HPP
#define PAYMENTPROCESSOR_HPP

#include "IPaymentProcessor.hpp"

class PaymentProcessor : public IPaymentProcessor {
public:
    Payment* processPayment(float amount, string spotId, string userId, string timing) override;
};

#endif
