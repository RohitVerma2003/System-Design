#pragma once
#include<string>
#include <iostream>
#include "../ITextview.h"
using namespace std;

class PlainText : public ITextview{
private:
    string text;
public:
    PlainText(string text) : text(text) {}

    void render() override{
        cout<<this->text;
    }
};