#include "../Headers/Room.hpp"

Room::Room(string id , int cap): id(id) , capacity(cap) , calendar(new Calendar()){}

bool Room::is_available(TimeSlot* slot){
    return !this->calendar->is_overlapping(slot);
}

void Room::book_slot(TimeSlot* slot , string meet_id){
    if(!this->is_available(slot)){
        cout<<"Room is not available for the given time..."<<endl;
        return;
    }

    this->calendar->add_slot(slot , meet_id);
}

int Room::get_capacity(){
    return this->capacity;
}

string Room::get_room_id(){
    return this->id;
}