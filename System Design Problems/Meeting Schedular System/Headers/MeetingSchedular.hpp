#include "Room.hpp"
#include "Meeting.hpp"
#include <mutex>

class MeetingSchedular{
private:
    vector<Room*> rooms;
    unordered_map<string , Meeting*> meetings;
    static MeetingSchedular* instance;
    static mutex mtx;
    MeetingSchedular();
public:
    static MeetingSchedular* get_instance();
    void add_room(Room* room);
    Meeting* book_meeting(TimeSlot* slot , int capacity , vector<Participant*> participants , string title , int start , int end , int date);
    void cancel_meeting(string meet_id);
};