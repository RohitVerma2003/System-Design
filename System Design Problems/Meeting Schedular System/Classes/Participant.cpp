#include "../Headers/Participant.hpp"

Participant::Participant(string id, string name, string email) : id(id), name(name), email(email), calendar(new Calendar()) {}

string Participant::get_id(){return this->id;}
string Participant::get_name(){return this->name;}
string Participant::get_email(){return this->email;}

void Participant::get_schedule(){
    for(auto ele : this->calendar->get_slots()){
        TimeSlot* slot = ele.first;
        string meet_id = ele.second;

        cout<<"Time Slot-> "<<slot->get_date()<<":"<<slot->get_start_time()<<" - "<<slot->get_end_time()<<endl;
    }
}

void Participant::notify(string message){
    cout<<message<<endl;
}