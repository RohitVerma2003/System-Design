#include "MeetObserver.hpp"
#include "Calendar.hpp"
#include <iostream>

class Participant : public MeetObserver{
private:
    string id , name , email;
    Calendar* calendar;
public:
    Participant(string id , string name , string email);
    string get_id();
    string get_name();
    string get_email();
    void get_schedule();
    void notify(string message);
};