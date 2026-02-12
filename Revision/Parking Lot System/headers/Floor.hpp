#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <string>
#include <unordered_map>
#include "ParkingSpot.hpp"
using namespace std;


class Floor{
private:
    int floorNumber;
    unordered_map<string , ParkingSpot*> spots;
public:
    Floor(int number);

    void setSpot(ParkingSpot* spot);
    unordered_map<string , ParkingSpot*> getSpots()const;
    int getFloorNumber() const;
};


#endif