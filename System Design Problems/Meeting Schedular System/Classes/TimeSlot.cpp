#include "../Headers/TimeSlot.hpp"

TimeSlot::TimeSlot(int start , int end , int date): start_time(start) , end_time(end) , date(date){}

int TimeSlot::get_date(){return this->date;}
int TimeSlot::get_start_time(){return this->start_time;}
int TimeSlot::get_end_time(){return this->end_time;}