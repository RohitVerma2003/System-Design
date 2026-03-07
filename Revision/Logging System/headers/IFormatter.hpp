#ifndef IFORMATTER_HPP
#define IFORMATTER_HPP

#include "./LogMessage.hpp"

class IFormatter{
public:
    virtual std::string format(LogMessage message) = 0;
};

#endif