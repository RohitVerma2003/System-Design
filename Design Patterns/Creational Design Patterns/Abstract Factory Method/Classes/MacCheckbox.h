#pragma once
#include <iostream>
#include "../Interfaces/ICheckbox.h"
using namespace std;

class MacCheckbox : public ICheckbox{
public:
    void paint() override{
        cout<<"Painting Mac Checkbox"<<endl;
    }

    void select() override{
        cout<<"Selecting Mac Checkbox"<<endl;
    }
}