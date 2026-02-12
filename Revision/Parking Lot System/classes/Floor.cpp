#include "../headers/Floor.hpp"
#include <iostream>

Floor::Floor(int number): floorNumber(number){}

void Floor::setSpot(ParkingSpot* spot){
    this->spots[spot->getSpotId()] = spot;
    cout << "[Floor " << this->floorNumber << "] Added parking spot: " << spot->getSpotId() << " for vehicle type: " << spot->getVehicleType() << endl;
}

int Floor::getFloorNumber() const{return this->floorNumber;}
unordered_map<string , ParkingSpot*> Floor::getSpots()const {return this->spots;}