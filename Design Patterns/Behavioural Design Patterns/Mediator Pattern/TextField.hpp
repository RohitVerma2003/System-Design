#include "UIComponent.hpp"
#include "Mediator.hpp"
#include <string>
#include <iostream>
using namespace std;
#pragma once

class TextField : public UIComponent{
private:
    string text;
public:
    TextField(Mediator* mediator): UIComponent(mediator) , text(""){}

    void set_text(string new_text){
        this->text = new_text;
        cout<<"New Text: "<<new_text<<endl;
        this->notify_mediator();
    }

    string get_text(){
        return this->text;
    }
};