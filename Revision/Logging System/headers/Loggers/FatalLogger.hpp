#ifndef FATAL_LOGGER_HPP
#define FATAL_LOGGER_HPP

#include "../ILogger.hpp"

class FatalLogger : public ILogger{
public:
    bool can_handle(LogMessage message) override;
};

#endif