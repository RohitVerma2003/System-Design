#include "../../headers/Loggers/InfoLogger.hpp"

bool InfoLogger::can_handle(LogMessage message){
    return message.level == INFO;
}