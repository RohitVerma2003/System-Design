#pragma once
#include <iostream>
#include "../ITextDecorator.h"
#include "../ITextview.h"
using namespace std;

class UnderlineText : public ITextDecorator{
public:
    UnderlineText(ITextview* textView) : ITextDecorator(textView){}

    void render() override{
        cout<<"<u>";
        this->text_view->render();
        cout<<"</u>";
    }
};