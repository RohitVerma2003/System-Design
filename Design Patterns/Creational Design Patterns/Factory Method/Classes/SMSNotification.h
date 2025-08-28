#pragma once
#include<string>
#include<iostream>
#include "../Interfaces/Notification.h"
using namespace std;

class SMSNotification : public Notification{
public:
    void send(const string& str) override{
        cout<<"Sending via sms: "<<str<<endl;
    }
};