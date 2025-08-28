#pragma once
#include "IButton.h"
#include "ICheckbox.h"

class GUIFactory{
public:
    virtual IButton* createButton() = 0;
    virtual ICheckbox* createCheckbox() = 0;
    virtual ~GUIFactory(){};
};