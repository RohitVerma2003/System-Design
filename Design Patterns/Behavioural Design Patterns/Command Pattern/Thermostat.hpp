#include <iostream>
using namespace std;
#pragma once

class Thermostat{
private:
    int temperature = 22;
public:
    void set_temperature(int temp){
        cout<<"Setting the thermostat temperature to "<<temp<<" C"<<endl;
        this->temperature = temp;
    }

    int get_temperature(){
        return this->temperature;
    }
};