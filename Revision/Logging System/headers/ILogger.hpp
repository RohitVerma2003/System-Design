#ifndef ILOGGER_HPP
#define ILOGGER_HPP

#include "./IAppender.hpp"
#include <vector>

class ILogger{
public:
    std::vector<IAppender*> observers;
    ILogger* next;

    void add_appender(IAppender* appender){
        observers.push_back(appender);
    }

    void notify_observers(LogMessage message){
        for(auto observer : observers){
            observer->append(message);
        }
    }

    virtual bool can_handle(LogMessage message) = 0;
    
    void log_message(LogMessage message){
        if(can_handle(message)) this->notify_observers(message);
        else if(this->next){
            this->next->log_message(message);
        }
    }
};

#endif