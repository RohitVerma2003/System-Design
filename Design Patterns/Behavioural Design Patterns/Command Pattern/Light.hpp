#include <iostream>
using namespace std;
#pragma once

class Light{
public:
    void turn_on(){
        cout<<"Turning the light ON"<<endl;
    }

    void turn_off(){
        cout<<"Turning the light OFF"<<endl;
    }
};