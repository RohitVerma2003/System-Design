#pragma once
#include<string>
#include<iostream>
using namespace std;

class EmailNotification : public Notification{
public:
    void send(const string& str) override{
        cout<<"Sending via email: "<<str<<endl;
    }
};