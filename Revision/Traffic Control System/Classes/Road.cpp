#include "../Headers/Road.hpp"

Road::Road(std::string name, SignalType type, int red, int yellow, int green): name(name){
    this->signal = new Signal(type , red , yellow , green);
}

Signal *Road::get_signal(){return this->signal;}

std::string Road::get_name(){return this->name;}
