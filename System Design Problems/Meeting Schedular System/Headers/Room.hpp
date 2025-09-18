#pragma once
#include "Calendar.hpp"
#include<iostream>

class Room{
private:
    string id;
    int capacity;
    Calendar* calendar;
public:
    Room(string id , int cap);
    bool is_available(TimeSlot* slot);
    void book_slot(TimeSlot* slot , string meet_id);
    int get_capacity();
    string get_room_id();
};