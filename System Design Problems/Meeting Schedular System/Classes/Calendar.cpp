#include "../Headers/Calendar.hpp"

void Calendar::add_slot(TimeSlot* slot , string meet_id){
    this->slots[slot] = meet_id;
}

bool Calendar::is_overlapping(TimeSlot* given_slot) {
    int given_start = given_slot->get_start_time();
    int given_end   = given_slot->get_end_time();
    int given_date = given_slot->get_date();

    for (auto& entry : this->slots) {
        TimeSlot* existing_slot = entry.first;

        if (existing_slot->get_date() == given_date) {
            int existing_start = existing_slot->get_start_time();
            int existing_end   = existing_slot->get_end_time();

            if (given_start < existing_end && existing_start < given_end) {
                return true;
            }
        }
    }

    return false;
}

unordered_map<TimeSlot* , string> Calendar::get_slots(){return this->slots;}