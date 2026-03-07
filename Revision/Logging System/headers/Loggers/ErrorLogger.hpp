#ifndef ERROR_LOGGER_HPP
#define ERROR_LOGGER_HPP

#include "../ILogger.hpp"

class ErrorLogger : public ILogger{
public:
    bool can_handle(LogMessage message) override;
};

#endif