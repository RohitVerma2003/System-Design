#pragma once
#include "../Classes/Request.hpp"

class IRequestHandler{
public:
    virtual void set_next(IRequestHandler* next) = 0;
    virtual void handle(Request request) = 0;
    ~IRequestHandler(){}
};