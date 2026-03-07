#ifndef LOGMESSAGE_HPP
#define LOGMESSAGE_HPP

#include "../enum.hpp"
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

class LogMessage{
public:
    std::string message;
    LogLevel level;
    std::string timestamp;

    LogMessage(std::string message , LogLevel level): message(message) , level(level){
        std::time_t now = std::time(nullptr);
        std::tm* localTime = std::localtime(&now);

        std::stringstream ss;
        ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");

        timestamp = ss.str();
    }
};


#endif