#include "FormMediator.hpp"
#include "TextField.hpp"
#include "PasswordField.hpp"
#include "Button.hpp"

int main(){
    FormMediator* form = new FormMediator();

    TextField* text_field = new TextField(form);
    PasswordField* password_field = new PasswordField(form);
    Button* button = new Button(form);

    form->set_text_field(text_field);
    form->set_password_field(password_field);
    form->set_button(button);

    text_field->set_text("");
    password_field->set_password("1234");
    button->click();

    return -1;
}