#pragma once
class ICheckbox{
public:
    virtual void paint() = 0;
    virtual void select() = 0;
    virtual ~ICheckbox(){};
};