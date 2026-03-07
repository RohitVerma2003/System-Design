#include "../headers/LogManager.hpp"

LogManager::LogManager(){
    this->info_logger = new InfoLogger();
    this->debug_logger = new DebugLogger();
    this->warn_logger = new WarnLogger();
    this->error_logger = new ErrorLogger();
    this->fatal_logger = new FatalLogger();
    this->head = build_chain();
}

LogManager& LogManager::get_instance(){
    static LogManager instance;
    return instance;
}

ILogger* LogManager::build_chain(){
    info_logger->next = debug_logger;
    debug_logger->next = warn_logger;
    warn_logger->next = error_logger;
    error_logger->next = fatal_logger;

    return info_logger;
}

void LogManager::add_appender(LogLevel level, IAppender* appender){
    switch (level){
    case INFO:
        info_logger->add_appender(appender);
        break;
    case DEBUG:
        debug_logger->add_appender(appender);
        break;
    case WARN:
        warn_logger->add_appender(appender);
        break;
    case ERROR:
        error_logger->add_appender(appender);
        break;
    case FATAL:
        fatal_logger->add_appender(appender);
        break;
    default:
        break;
    }
}

void LogManager::info(std::string message){
    head->log_message(LogMessage(message , INFO));
}

void LogManager::debug(std::string message){
    head->log_message(LogMessage(message , DEBUG));
}

void LogManager::warn(std::string message){
    head->log_message(LogMessage(message , WARN));
}

void LogManager::error(std::string message){
    head->log_message(LogMessage(message , ERROR));
}

void LogManager::fatal(std::string message){
    head->log_message(LogMessage(message , FATAL));
}