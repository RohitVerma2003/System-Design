#include "../Headers/MeetingSchedular.hpp"

MeetingSchedular* MeetingSchedular::instance = nullptr;
mutex MeetingSchedular::mtx;

MeetingSchedular::MeetingSchedular(){}

MeetingSchedular* MeetingSchedular::get_instance(){
    if(instance == nullptr){
        lock_guard<mutex> guard(mtx);
        if(instance == nullptr){
            instance = new MeetingSchedular();
        }
    }

    return instance;
}

void MeetingSchedular::add_room(Room* room){
    this->rooms.push_back(room);
}

Meeting* MeetingSchedular::book_meeting(TimeSlot* slot , int capacity , vector<Participant*> participants , string title , int start_time , int end_time , int date){
    for(Room* room : this->rooms){
        if(room->get_capacity() >= capacity){
            if(room->is_available(slot)){
                string meet_id = to_string(rand());
                room->book_slot(slot , meet_id);
                
                Meeting* meet = new Meeting(meet_id , title , room->get_room_id() , participants , start_time , end_time , date);
                this->meetings[meet_id] = meet;
                return meet;
            }
        }
    }

    cout<<"No rooms available for the given constraints..."<<endl;
    return nullptr;
}

void MeetingSchedular::cancel_meeting(string meet_id){
    this->meetings.erase(meet_id);
}