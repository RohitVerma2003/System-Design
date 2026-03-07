#ifndef INFO_LOGGER_HPP
#define INFO_LOGGER_HPP

#include "../ILogger.hpp"

class InfoLogger : public ILogger{
public:
    bool can_handle(LogMessage message) override;
};

#endif