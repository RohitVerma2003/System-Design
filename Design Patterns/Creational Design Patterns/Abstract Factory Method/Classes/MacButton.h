#pragma once
#include<iostream>
#include "../Interfaces/IButton.h"
using namespace std;

class MacButton : public IButton{
public:
    void paint() override{
        cout<<"Painting Mac Button"<<endl;
    }

    void click() override{
        cout<<"Clicking The Mac Button"<<endl;
    }
};