#ifndef ENUM_HPP
#define ENUM_HPP

#include <string>

enum LogLevel{
    INFO,
    DEBUG,
    WARN,
    ERROR,
    FATAL
};

inline std::string to_string(LogLevel level) {
    switch(level) {
        case INFO: return "INFO";
        case DEBUG: return "DEBUG";
        case WARN: return "WARN";
        case ERROR: return "ERROR";
        case FATAL: return "FATAL";
        default: return "UNKNOWN";
    }
}

#endif