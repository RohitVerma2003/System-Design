#include <iostream>
#include <unordered_map>
#include "headers/ParkingLot.hpp"
#include "headers/ParkingSpot.hpp"
#include "headers/Vehicle.hpp"
#include "headers/User.hpp"
#include "headers/Floor.hpp"
#include "headers/ParkingSpotFinder.hpp"
#include "headers/PaymentProcessor.hpp"
#include "enum.hpp"

using namespace std;

int main(){
    cout << "Starting Parking Lot System..." << endl;
    
    Floor* floor1 = new Floor(1);
    Floor* floor2 = new Floor(2);

    ParkingSpot* bikeSpot1 = new ParkingSpot("bike1" , VehicleType::BIKE , 1);
    ParkingSpot* carSpot1 = new ParkingSpot("car1" , VehicleType::CAR , 1);
    ParkingSpot* truckSpot1 = new ParkingSpot("truck1" , VehicleType::TRUCK , 1);

    ParkingSpot* bikeSpot2 = new ParkingSpot("bike2" , VehicleType::BIKE , 2);
    ParkingSpot* carSpot2 = new ParkingSpot("car2" , VehicleType::CAR , 2);

    floor1->setSpot(bikeSpot1);
    floor1->setSpot(carSpot1);
    floor1->setSpot(truckSpot1);

    floor2->setSpot(bikeSpot2);
    floor2->setSpot(carSpot2);

    unordered_map<int, Floor*> floorsMap;
    floorsMap[floor1->getFloorNumber()] = floor1;
    floorsMap[floor2->getFloorNumber()] = floor2;
    
    IParkingSpotFinder* spotFinder = new ParkingSpotFinder(floorsMap);
    IPaymentProcessor* paymentProcessor = new PaymentProcessor();
    
    ParkingLot* parkingLot = new ParkingLot(spotFinder, paymentProcessor);

    parkingLot->setFloor(floor1);
    parkingLot->setFloor(floor2);
    cout << "Added 2 floors to parking lot" << endl;

    Vehicle* vehicle1 = new Vehicle("activa123" , VehicleType::BIKE);
    User* user1 = new User("Rohit" , vehicle1);
    cout << "Created User 1: Rohit with vehicle: activa123" << endl;

    Vehicle* vehicle2 = new Vehicle("honda123" , VehicleType::BIKE);
    User* user2 = new User("Rohit" , vehicle2);
    cout << "Created User 2: Rohit with vehicle: honda123" << endl;

    cout << "\n--- Attempting to park Vehicle 1 ---" << endl;
    if(parkingLot->isSpotAvailable(VehicleType::BIKE)){
        cout << "Spot available for BIKE type vehicle" << endl;
        parkingLot->parkVehicle(user1);
        cout << "Vehicle 1 parked successfully" << endl;
    } else {
        cout << "No spot available for BIKE type vehicle" << endl;
    }

    cout << "\n--- Attempting to park Vehicle 2 ---" << endl;
    if(parkingLot->isSpotAvailable(VehicleType::BIKE)){
        cout << "Spot available for BIKE type vehicle" << endl;
        parkingLot->parkVehicle(user2);
        cout << "Vehicle 2 parked successfully" << endl;
    } else {
        cout << "No spot available for BIKE type vehicle" << endl;
    }

    cout << "\n--- Unparking Vehicles ---" << endl;
    cout << "Unparking vehicle 1..." << endl;
    parkingLot->unparkVehicle(user1);
    cout << "Vehicle 1 unparked successfully" << endl;
    
    cout << "Unparking vehicle 2..." << endl;
    parkingLot->unparkVehicle(user2);
    cout << "Vehicle 2 unparked successfully" << endl;
    
    cout << "\n--- Program completed successfully ---" << endl;
}