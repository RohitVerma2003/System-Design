#include "Mediator.hpp"
#include "UIComponent.hpp"
#include "TextField.hpp"
#include "PasswordField.hpp"
#include "Button.hpp"
#include <iostream>
using namespace std;

class FormMediator : public Mediator{
private:
    TextField* text_field;
    PasswordField* password_field;
    Button* button;
public:
    FormMediator():text_field(nullptr) , password_field(nullptr) , button(nullptr){}

    void set_text_field(TextField* text){
        this->text_field = text;
    }

    void set_password_field(PasswordField* password){
        this->password_field = password;
    }

    void set_button(Button* button){
        this->button = button;
    }

    void component_changes(UIComponent* component) override{
        if(component == this->text_field || component == this->password_field){
            bool button_enable_value = !this->text_field->get_text().empty() && !this->password_field->get_password().empty();
            this->button->set_enable(button_enable_value);
        }else if(component == this->button){
            if(this->button->is_enable()){
                bool is_valid = this->text_field->get_text() == "admin" && this->password_field->get_password() == "1234";

                if(is_valid){
                    cout<<"Login Successfull..."<<endl;
                }else{
                    cout<<"Wrong Credentials..."<<endl;
                }
            }else{
                cout<<"Username or Password is empty..."<<endl;
            }
        }
    }
};