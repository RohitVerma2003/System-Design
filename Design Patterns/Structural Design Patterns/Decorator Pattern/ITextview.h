#pragma once
class ITextview{
public:
    virtual void render() = 0;
    virtual ~ITextview(){};
};