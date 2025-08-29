#pragma once
#include <iostream>
#include "../ITextDecorator.h"
#include "../ITextview.h"
using namespace std;

class BoldText : public ITextDecorator{
public:
    BoldText(ITextview* textView) : ITextDecorator(textView){}

    void render() override{
        cout<<"<b>";
        this->text_view->render();
        cout<<"</b>";
    }
};