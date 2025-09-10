#include "Mediator.hpp"
#pragma once

class UIComponent{
private:
    Mediator* mediator;
public:
    UIComponent(Mediator* mediator): mediator(mediator){}

    void notify_mediator(){
        this->mediator->component_changes(this);
    }

    ~UIComponent(){}
};