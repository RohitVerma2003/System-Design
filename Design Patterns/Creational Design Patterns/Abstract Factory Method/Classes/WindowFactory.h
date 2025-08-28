#pragma once
#include "../Interfaces/GUIFactory.h"
#include "../Interfaces/IButton.h"
#include "../Interfaces/ICheckbox.h"
#include "WindowButton.h"
#include "WindowCheckbox.h"

class WindowFactory : public GUIFactory{
public:
    IButton* createButton() override{
        return new WindowButton();
    }

    ICheckbox* createCheckbox() override{
        return new WindowCheckbox();
    }
};