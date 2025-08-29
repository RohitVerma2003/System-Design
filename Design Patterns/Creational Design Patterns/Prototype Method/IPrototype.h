#pragma once
class IPrototype{
public:
    virtual IPrototype* clone() = 0;
    virtual ~IPrototype(){};
};