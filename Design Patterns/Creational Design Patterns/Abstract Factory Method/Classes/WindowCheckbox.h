#pragma once
#include <iostream>
#include "../Interfaces/ICheckbox.h"
using namespace std;

class WindowCheckbox : public ICheckbox{
public:
    void paint() override{
        cout<<"Painting Window Checkbox"<<endl;
    }

    void select() override{
        cout<<"Selecting Window Checkbox"<<endl;
    }
};