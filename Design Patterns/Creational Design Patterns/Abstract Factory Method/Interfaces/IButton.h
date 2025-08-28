#pragma once
class IButton{
public:
    virtual void paint() = 0;
    virtual void click() = 0;
    virtual ~IButton(){};
};