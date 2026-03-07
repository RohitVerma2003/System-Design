#include "../../headers/Loggers/ErrorLogger.hpp"

bool ErrorLogger::can_handle(LogMessage message){
    return message.level == ERROR;
}