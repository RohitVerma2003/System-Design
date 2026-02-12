#include "../headers/ParkingLot.hpp"

ParkingLot::ParkingLot(IParkingSpotFinder* spotFinder, IPaymentProcessor* paymentProcessor) 
    : spotFinder(spotFinder), paymentProcessor(paymentProcessor) {}

void ParkingLot::setFloor(Floor* floor){
    this->floors[floor->getFloorNumber()] = floor;
    cout << "[ParkingLot] Floor " << floor->getFloorNumber() << " added to parking lot" << endl;
}
void ParkingLot::setTicket(Ticket* ticket){this->tickets[ticket->getTicketId()] = ticket;}

bool ParkingLot::isSpotAvailable(VehicleType type){
    ParkingSpot* spot = this->spotFinder->findAvailableSpot(type);
    return spot != NULL;
}

void ParkingLot::parkVehicle(User* user){
    cout << "[ParkingLot] Parking vehicle for user: " << user->getName() << endl;
    Vehicle* vehicle = user->getVehicle();
    cout << "[ParkingLot] Vehicle Number: " << vehicle->getVehicleNumber() << endl;
    ParkingSpot* spot = this->spotFinder->findAvailableSpot(vehicle->getVehicleType());

    if(spot != NULL){
        spot->setIsOccupied(true);
        spot->setOccupiedBy(vehicle);
        cout << "[ParkingLot] Vehicle marked as occupied at spot: " << spot->getSpotId() << endl;

        Ticket* ticket = new Ticket(spot , user->getName() , "", this->paymentProcessor);
        user->setTicket(ticket);   
        this->setTicket(ticket);
        cout << "[ParkingLot] Ticket generated with ID: " << ticket->getTicketId() << endl;
    }
}

void ParkingLot::unparkVehicle(User* user){
    cout << "[ParkingLot] Unparking vehicle for user: " << user->getName() << endl;
    Ticket* ticket = user->getTicket();
    ParkingSpot* spot = ticket->getSpot();
    cout << "[ParkingLot] Spot ID: " << spot->getSpotId() << " is being vacated" << endl;

    spot->setIsOccupied(false);
    spot->setOccupiedBy(NULL);
    cout << "[ParkingLot] Spot " << spot->getSpotId() << " is now available" << endl;
}