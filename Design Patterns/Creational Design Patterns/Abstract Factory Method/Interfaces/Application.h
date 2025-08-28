#pragma once
#include "IButton.h"
#include "ICheckbox.h"
#include "GUIFactory.h"

class Application{
private:
    IButton* button;
    ICheckbox* checkbox;
public:
    Application(GUIFactory* factory){
        this->button = factory->createButton();
        this->checkbox = factory->createCheckbox();
    }

    void renderUI(){
        this->button->paint();
        this->checkbox->paint();
    }

    void clickButton(){
        this->button->click();
    }

    void selectCheckbox(){
        this->checkbox->select();
    }

    ~Application(){
        delete button;
        delete  checkbox;
    }
};