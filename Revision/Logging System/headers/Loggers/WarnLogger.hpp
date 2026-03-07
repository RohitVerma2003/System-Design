#ifndef WARN_LOGGER_HPP
#define WARN_LOGGER_HPP

#include "../ILogger.hpp"

class WarnLogger : public ILogger{
public:
    bool can_handle(LogMessage message) override;
};

#endif