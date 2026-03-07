#ifndef DEBUG_LOGGER_HPP
#define DEBUG_LOGGER_HPP

#include "../ILogger.hpp"

class DebugLogger : public ILogger{
public:
    bool can_handle(LogMessage message) override;
};

#endif