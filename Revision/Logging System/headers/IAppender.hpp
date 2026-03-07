#ifndef IAPPENDER_HPP
#define IAPPENDER_HPP

#include "./IFormatter.hpp"

class IAppender{
protected:
    IFormatter* formatter;
public:
    IAppender(IFormatter* formatter): formatter(formatter){}
    virtual void append(LogMessage message) = 0;
    virtual ~IAppender() = default;
};

#endif