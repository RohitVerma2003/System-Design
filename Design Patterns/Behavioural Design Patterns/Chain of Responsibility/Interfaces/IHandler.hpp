#include "IRequestHandler.hpp"
#pragma once

class IHandler : public IRequestHandler{
protected:
    IRequestHandler* next_handler;
    void forward_req(Request request){
        if(this->next_handler) this->next_handler->handle(request);
    }
public:
    IHandler(): next_handler(nullptr){}

    void set_next(IRequestHandler* next) override{
        this->next_handler = next;
    }
};