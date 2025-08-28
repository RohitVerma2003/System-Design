#pragma once
#include "../Interfaces/NotificationCreator.h"
#include "EmailNotification.h"

class EmailNotificationCreator : public NotificationCreator{
public:
    Notification* createNotification() override{
        return new EmailNotification();
    }
};