#include "../Headers/Signal.hpp"

Signal::Signal(SignalType type, int red, int yellow, int green): current_state(type) , red_duration(red) , yellow_duration(yellow) , green_duration(green){}

Signal *Signal::get_signal(){return this;}
