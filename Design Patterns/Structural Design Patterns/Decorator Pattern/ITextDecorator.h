#pragma once
#include "ITextview.h"

class ITextDecorator : public ITextview{
protected:
    ITextview* text_view;
public:
    ITextDecorator(ITextview* textView) : text_view(textView){}
};