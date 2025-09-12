#include "ParkingSpot.hpp"
#include "ParkingTicket.hpp"
#include "Vehicle.hpp"
#include "PaymentSystem.hpp"
#include <map>
#include <vector>
#include <string>
#include <mutex>
using namespace std;

class ParkingLot{
private:
    int total_size , compact_space , handicapped_space , small_space , large_space;
    map<string , ParkingTicket*> spots;
    vector<string> entry_gates , exit_gates;
    static ParkingLot* instance;
    static mutex mtx;

    string find_spots(VehicleType vehicle_type);
    ParkingLot(int size , double rates , vector<string>& entry , vector<string>& exit);
public:
    double per_hour_rates;

    static ParkingLot* get_instance(int size , double rates , vector<string>& entry , vector<string>& exit);
    ParkingTicket* park_vehicle(Vehicle vehicle , int entry , string gate);
    bool unpark_vehicle(ParkingTicket* ticket , int exit_time , string exit_gate , PaymentType pay_type);
};