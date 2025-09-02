#pragma once
class Renderer{
public:
    virtual ~Renderer(){}
    virtual void render_rectangle(int length , int breadth) = 0;
    virtual void render_circle(int radius) = 0;
};