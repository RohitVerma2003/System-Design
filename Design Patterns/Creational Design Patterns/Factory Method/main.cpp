#include<iostream>
#include "Interfaces/NotificationCreator.h"
#include "Classes/EmailNotificationCreator.h"
#include "Classes/WhatsappNotificationCreator.h"
#include "Classes/SMSNotificationCreator.h"
using namespace std;

int main(){
    NotificationCreator* creator;

    creator = new EmailNotificationCreator();
    creator->send("Email Notification...");
    delete creator;

    creator = new WhatsappNotificationCreator();
    creator->send("Wahstapp Notification...");
    delete creator;

    creator = new SMSNotificationCreator();
    creator->send("SMS Notification...");
    delete creator;
    return -1;
}