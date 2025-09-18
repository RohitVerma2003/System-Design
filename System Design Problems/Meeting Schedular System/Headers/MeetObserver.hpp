#pragma once
#include<string>
using namespace std;

class MeetObserver{
public:
    virtual void notify(string message) = 0;
};