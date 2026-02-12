#include "../headers/PaymentProcessor.hpp"
#include <iostream>
#include <thread>
#include <chrono>
#include <random>
using namespace std;

Payment* PaymentProcessor::processPayment(float amount, string spotId, string userId, string timing) {
    cout << "[PaymentProcessor] Processing payment of $" << amount << " for user: " << userId << endl;
    cout << "[PaymentProcessor] Payment is initializing..." << endl << flush;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "[PaymentProcessor] Payment successful!" << endl;
    
    return new Payment(amount, spotId, userId, timing);
}
