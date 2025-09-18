#include "../Headers/Meeting.hpp"

Meeting::Meeting(string id , string title , string room , vector<Participant*> participants , int start , int end , int date): id(id) , title(title) , room_id(room) , participants(participants) , timing(new TimeSlot(start , end,  date)){}

string Meeting::get_id(){return this->id;}
string Meeting::get_title(){return this->title;}
string Meeting::get_room_id(){return this->room_id;}
TimeSlot* Meeting::get_time_slot(){return this->timing;}

void Meeting::show_participants(){
    cout<<"Participants IDs-> ";
    for(auto participant : this->participants){
        cout<<participant->get_id()<<", ";
    }
    cout<<endl;
}

void Meeting::show_timing(){
    TimeSlot* slot = this->get_time_slot();
    cout<<"Timings-> "<<slot->get_date()<<": "<<slot->get_start_time()<<" - "<<slot->get_end_time()<<endl;
}

void Meeting::notify_participants(){
    string message = "Join the meeting ID: ";
    message += this->get_id();
    for(auto participant : this->participants){
        participant->notify(message);
    }
}