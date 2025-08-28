#pragma once
#include<string>
#include<iostream>
#include "../Interfaces/Notification.h"
using namespace std;

class WhatsappNotification : public Notification{
public:
    void send(const string& str) override{
        cout<<"Sending via whatsapp: "<<str<<endl;
    }
};