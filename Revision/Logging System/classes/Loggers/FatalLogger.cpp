#include "../../headers/Loggers/FatalLogger.hpp"

bool FatalLogger::can_handle(LogMessage message){
    return message.level == FATAL;
}