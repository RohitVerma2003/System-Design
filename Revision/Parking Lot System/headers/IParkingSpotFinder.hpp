#ifndef IPARKINGSPOTFINDER_HPP
#define IPARKINGSPOTFINDER_HPP

#include "ParkingSpot.hpp"
#include "../enum.hpp"

class IParkingSpotFinder {
public:
    virtual ~IParkingSpotFinder() {}
    virtual ParkingSpot* findAvailableSpot(VehicleType type) = 0;
};

#endif
