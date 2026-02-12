#include "../headers/ParkingSpotFinder.hpp"
#include <iostream>
using namespace std;

ParkingSpotFinder::ParkingSpotFinder(unordered_map<int, Floor*> floors) : floors(floors) {}

ParkingSpot* ParkingSpotFinder::findAvailableSpot(VehicleType type) {
    cout << "[ParkingSpotFinder] Checking availability for vehicle type: " << type << endl;
    for(auto ele : this->floors) {
        int floorNum = ele.first;
        auto floor = ele.second;
        cout << "  Checking Floor " << floorNum << "..." << endl;

        for(auto ele : floor->getSpots()) {
            auto spotId = ele.first;
            auto spot = ele.second;

            if(spot->getVehicleType() == type && !spot->isOccupied()) {
                cout << "  Found available spot: " << spotId << " on Floor " << floorNum << endl;
                return spot;
            }
        }
    }
    cout << "  No available spots found" << endl;
    return NULL;
}
