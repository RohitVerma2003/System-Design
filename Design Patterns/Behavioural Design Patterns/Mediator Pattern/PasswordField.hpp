#include "UIComponent.hpp"
#include "Mediator.hpp"
#include <iostream>
#include <string>
using namespace std;
#pragma once

class PasswordField : public UIComponent{
protected:
    string password;
public:
    PasswordField(Mediator* mediator): UIComponent(mediator) , password(""){}

    void set_password(string new_password){
        this->password = new_password;
        cout<<"New Password: "<<new_password<<endl;
        this->notify_mediator();
    }

    string get_password(){
        return this->password;
    }
};