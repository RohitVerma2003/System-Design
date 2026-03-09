#ifndef ENUM_HPP
#define ENUM_HPP

#include <string>

enum SignalType{
    RED,
    YELLOW,
    GREEN
};

inline std::string to_string(SignalType signal) {
    switch(signal) {
        case RED: return "RED";
        case YELLOW: return "YELLOW";
        case GREEN: return "GREEN";
        default: return "UNKNOWN";
    }
}

#endif