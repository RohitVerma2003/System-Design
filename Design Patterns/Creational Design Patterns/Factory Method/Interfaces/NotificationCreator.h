#pragma once
#include<string>
#include "Notification.h"
using namespace std;

class NotificationCreator{
public:
    virtual Notification* createNotification() = 0;
    void send(const string& str){
        Notification* notification = createNotification();
        notification->send(str);
        delete notification;
    }
    virtual ~NotificationCreator(){};
};
