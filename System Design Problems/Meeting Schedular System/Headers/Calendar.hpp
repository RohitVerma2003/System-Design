#pragma once
#include "TimeSlot.hpp"
#include <unordered_map>
#include <string>
using namespace std;

class Calendar{
private:
    unordered_map<TimeSlot* , string> slots;
public:
    unordered_map<TimeSlot* , string> get_slots();
    bool is_overlapping(TimeSlot* given_slot);
    void add_slot(TimeSlot* slot , string meet_id);
};