#include "../../headers/Formatters/TextFormatter.hpp"
#include <sstream>

std::string TextFormatter::format(LogMessage message){
    std::stringstream ss;
    ss << "[" << to_string(message.level) << "] " << message.timestamp << " " << message.message;
    return ss.str();
}