#include "TimeSlot.hpp"
#include "Participant.hpp"
#include <string>
#include <vector>

class Meeting{
private:
    string id , title , room_id;
    vector<Participant*> participants;
    TimeSlot* timing;
public:
    Meeting(string id , string title , string room , vector<Participant*> participants , int start , int end , int date);
    
    string get_id();
    string get_title();
    string get_room_id();
    void show_participants();
    void show_timing();
    TimeSlot* get_time_slot();
    void notify_participants();
};