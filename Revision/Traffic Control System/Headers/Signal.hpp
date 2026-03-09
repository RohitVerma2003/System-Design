#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include "../enum.hpp"

class Signal{
public:
    SignalType current_state;
    int red_duration , yellow_duration , green_duration;

    Signal(SignalType type , int red , int yellow , int green);
    Signal* get_signal();
};

#endif