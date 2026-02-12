#include "../headers/ParkingSpot.hpp"
#include <iostream>

ParkingSpot::ParkingSpot(string spotid, VehicleType type , int floor): spotId(spotid) , vechicleType(type) , occupiedBy(NULL), occupied(false), floor(floor){}

string ParkingSpot::getSpotId() const{return this->spotId;}
VehicleType ParkingSpot::getVehicleType() const{return this->vechicleType;}
void ParkingSpot::setIsOccupied(bool value) {
    this->occupied = value;
    cout << "[ParkingSpot " << this->spotId << "] Status changed to: " << (value ? "OCCUPIED" : "AVAILABLE") << endl;
}
bool ParkingSpot::isOccupied() const{return this->occupied;}
Vehicle* ParkingSpot::getOccupiedBy() const{return this->occupiedBy;}
void ParkingSpot::setOccupiedBy(Vehicle* vechicle){
    this->occupiedBy = vechicle;
    if(vechicle != NULL){
        cout << "[ParkingSpot " << this->spotId << "] Now occupied by vehicle: " << vechicle->getVehicleNumber() << endl;
    } else {
        cout << "[ParkingSpot " << this->spotId << "] Vehicle removed" << endl;
    }
}
int ParkingSpot::getFloor() const{return this->floor;}

