#ifndef PARKINGSPOTFINDER_HPP
#define PARKINGSPOTFINDER_HPP

#include "IParkingSpotFinder.hpp"
#include <unordered_map>
#include "Floor.hpp"
using namespace std;

class ParkingSpotFinder : public IParkingSpotFinder {
private:
    unordered_map<int, Floor*> floors;
    
public:
    ParkingSpotFinder(unordered_map<int, Floor*> floors);
    ParkingSpot* findAvailableSpot(VehicleType type) override;
};

#endif
