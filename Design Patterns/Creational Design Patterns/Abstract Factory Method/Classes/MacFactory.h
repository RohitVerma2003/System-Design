#pragma once
#include "../Interfaces/GUIFactory.h"
#include "../Interfaces/IButton.h"
#include "../Interfaces/ICheckbox.h"
#include "MacButton.h"
#include "MacCheckbox.h"

class WindowFactory : public GUIFactory{
public:
    IButton* createButton() override{
        return new MacButton();
    }

    ICheckbox* createButton() override{
        return new MacCheckbox();
    }
}