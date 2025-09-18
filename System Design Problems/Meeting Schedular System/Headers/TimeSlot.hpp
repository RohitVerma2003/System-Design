#pragma once

class TimeSlot{
private:
    int start_time , end_time , date;
public:
    TimeSlot(int start , int end , int date);
    int get_start_time();
    int get_end_time();
    int get_date();
};