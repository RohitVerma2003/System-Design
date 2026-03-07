#include "../../headers/Loggers/DebugLogger.hpp"

bool DebugLogger::can_handle(LogMessage message){
    return message.level == DEBUG;
}