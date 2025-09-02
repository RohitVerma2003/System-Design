#include "./Interfaces/Renderer.hpp"
#include <iostream>
using namespace std;

class VectorRenderer : public Renderer{
public:
    void render_rectangle(int length , int breadth) override{
        cout<<"Rendering vector rectangle: "<<length<<","<<breadth<<endl;
    }

    void render_circle(int radius) override{
        cout<<"Rendering vector circle: "<<radius<<endl;
    }
};