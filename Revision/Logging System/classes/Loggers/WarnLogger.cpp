#include "../../headers/Loggers/WarnLogger.hpp"

bool WarnLogger::can_handle(LogMessage message){
    return message.level == WARN;
}