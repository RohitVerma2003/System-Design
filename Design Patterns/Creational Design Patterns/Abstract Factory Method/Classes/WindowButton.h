#pragma once
#include<iostream>
#include "../Interfaces/IButton.h"
using namespace std;

class WindowButton : public IButton{
public:
    void paint() override{
        cout<<"Painting Window Button"<<endl;
    }

    void click() override{
        cout<<"Clicking The Window Button"<<endl;
    }
};