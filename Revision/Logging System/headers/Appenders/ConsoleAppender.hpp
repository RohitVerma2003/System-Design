#ifndef CONSOLE_APPENDER_HPP
#define CONSOLE_APPENDER_HPP

#include "../IAppender.hpp"
#include <mutex>

class ConsoleAppender: public IAppender{
private:
    static std::mutex mt;
public:
    ConsoleAppender(IFormatter* formatter): IAppender(formatter) {}
    void append(LogMessage message) override;
};

#endif