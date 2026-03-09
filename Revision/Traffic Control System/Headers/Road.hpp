#ifndef ROAD_HPP
#define ROAD_HPP

#include <string>
#include "./Signal.hpp"

class Road{
public:
    std::string name;
    Signal* signal;

    Road(std::string name , SignalType type , int red , int yellow , int green);
    Signal* get_signal();
    std::string get_name();
};

#endif