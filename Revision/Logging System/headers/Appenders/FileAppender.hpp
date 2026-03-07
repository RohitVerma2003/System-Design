#ifndef FILE_APPENDER_HPP
#define FILE_APPENDER_HPP

#include "../IAppender.hpp"
#include <mutex>

class FileAppender: public IAppender{
private:
    static std::mutex mt;
public:
    FileAppender(IFormatter* formatter): IAppender(formatter) {}
    void append(LogMessage message) override;
};

#endif