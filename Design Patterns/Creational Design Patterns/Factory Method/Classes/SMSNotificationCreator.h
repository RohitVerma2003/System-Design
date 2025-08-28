#pragma once
#include "../Interfaces/NotificationCreator.h"
#include "SMSNotification.h"

class SMSNotificationCreator : public NotificationCreator{
public:
    Notification* createNotification() override{
        return new SMSNotification();
    }
};