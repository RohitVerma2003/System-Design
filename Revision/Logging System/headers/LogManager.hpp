#ifndef LOG_MANAGER_HPP
#define LOG_MANAGER_HPP

#include "ILogger.hpp"
#include "Loggers/InfoLogger.hpp"
#include "Loggers/DebugLogger.hpp"
#include "Loggers/WarnLogger.hpp"
#include "Loggers/ErrorLogger.hpp"
#include "Loggers/FatalLogger.hpp"

class LogManager{
private:
    LogManager();
    LogManager(const LogManager&) = delete;
    LogManager& operator=(const LogManager&) = delete;

    ILogger* head;
    ILogger* info_logger;
    ILogger* debug_logger;
    ILogger* warn_logger;
    ILogger* error_logger;
    ILogger* fatal_logger;
public:
    static LogManager& get_instance();
    ILogger* build_chain();
    void add_appender(LogLevel level, IAppender* appender);

    void info(std::string message);
    void debug(std::string message);
    void warn(std::string message);
    void error(std::string message);
    void fatal(std::string message);

    virtual ~LogManager() = default;
};

#endif