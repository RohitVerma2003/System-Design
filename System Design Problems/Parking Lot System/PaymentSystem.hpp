#include "ParkingTicket.hpp"
#include <string>
using namespace std;

enum class PaymentType{
    CASH , CARD
};

class PaymentSystem{
private:
    string id;
    ParkingTicket* parking_ticket;
    void display_info();
    bool status;
public: 
    int occupancy_time;
    double charge;
    PaymentType payment_type;

    PaymentSystem(string id , ParkingTicket* ticket);
    void calculate_payment(int exit_time , double rate);
    bool make_payment(PaymentType type);
};