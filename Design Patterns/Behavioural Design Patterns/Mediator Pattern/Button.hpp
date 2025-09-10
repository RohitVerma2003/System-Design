#include "UIComponent.hpp"
#include "Mediator.hpp"
#pragma once

class Button : public UIComponent{
private:
    bool enabled;
public:
    Button(Mediator* mediator) : UIComponent(mediator) , enabled(false){}

    void click(){
        this->notify_mediator();
    }

    void set_enable(bool value){
        this->enabled = value;
    }

    bool is_enable(){
        return this->enabled;
    }
};