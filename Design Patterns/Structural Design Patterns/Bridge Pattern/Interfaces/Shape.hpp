#include "Renderer.hpp"
#pragma once
class Shape{
protected:
    Renderer* renderer;
public:
    Shape(Renderer* renderer){
        this->renderer = renderer;
    }

    virtual ~Shape(){}
    virtual void draw() = 0;
};