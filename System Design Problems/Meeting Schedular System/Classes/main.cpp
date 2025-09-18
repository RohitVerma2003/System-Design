#include "../Headers/MeetingSchedular.hpp"

int main(){
    MeetingSchedular* schedular = new MeetingSchedular();

    Participant* p1 = new Participant("001" , "Rohit" , "rohit@gmail.com");
    Participant* p2 = new Participant("002" , "Harsh" , "harsh@gmail.com");

    Room* room1 = new Room("F1" , 6);
    Room* room2 = new Room("F2" , 4);

    schedular->add_room(room1);
    schedular->add_room(room2);

    Meeting* meet1 = schedular->book_meeting(new TimeSlot(1 , 2 , 4) , 2 , {p1 , p2} , "AWS" , 1 , 2 , 4);
    Meeting* meet2 = schedular->book_meeting(new TimeSlot(1 , 2 , 4) , 2 , {p1 , p2} , "AWS" , 1 , 2 , 4);
    
    if(meet1){
        meet1->notify_participants();
        cout<<"Meeting Schduling - Meet1"<<endl;
        cout<<"Meeting ID-> "<<meet1->get_id()<<endl;
        cout<<"Meeting Title-> "<<meet1->get_title()<<endl;
        cout<<"Room ID-> "<<meet1->get_room_id()<<endl;
        meet1->show_participants();
        meet1->show_timing();
        cout<<endl;
    }
    
    if(meet2){
        meet2->notify_participants();
        cout<<"Meeting Schduling - Meet2"<<endl;
        cout<<"Meeting ID-> "<<meet2->get_id()<<endl;
        cout<<"Meeting Title-> "<<meet2->get_title()<<endl;
        cout<<"Room ID-> "<<meet2->get_room_id()<<endl;
        meet2->show_participants();
        meet2->show_timing();
    }
    
    Meeting* meet3 = schedular->book_meeting(new TimeSlot(1 , 2 , 4) , 2 , {p1 , p2} , "AWS" , 1 , 2 , 4);
    return 0;
}