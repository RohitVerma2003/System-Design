#pragma once
#include "../Interfaces/NotificationCreator.h"
#include "WhatsappNotification.h"

class WhatsappNotificationCreator : public NotificationCreator{
public:
    Notification* createNotification() override{
        return new WhatsappNotification();
    }
};