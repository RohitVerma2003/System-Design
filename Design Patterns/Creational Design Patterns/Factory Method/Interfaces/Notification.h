#pragma once
#include <string>
using namespace std;

class Notification{
public:
    virtual void send(const string& str) = 0;
    virtual ~Notification(){};
};