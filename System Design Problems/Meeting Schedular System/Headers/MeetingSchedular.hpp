#include "Room.hpp"
#include "Meeting.hpp"

class MeetingSchedular{
private:
    vector<Room*> rooms;
    unordered_map<string , Meeting*> meetings;
public:
    void add_room(Room* room);
    Meeting* book_meeting(TimeSlot* slot , int capacity , vector<Participant*> participants , string title , int start , int end , int date);
    void cancel_meeting(string meet_id);
};