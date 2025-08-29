#pragma once
#include <iostream>
#include "../ITextDecorator.h"
#include "../ITextview.h"
using namespace std;

class ItalicText : public ITextDecorator{
public:
    ItalicText(ITextview* textView) : ITextDecorator(textView){}

    void render() override{
        cout<<"<i>";
        this->text_view->render();
        cout<<"</i>";
    }
};