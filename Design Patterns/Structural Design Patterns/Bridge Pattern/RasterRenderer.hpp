#include "./Interfaces/Renderer.hpp"
#include <iostream>
using namespace std;

class RasterRenderer : public Renderer{
public:
    void render_rectangle(int length , int breadth) override{
        cout<<"Rendering raster rectangle: "<<length<<","<<breadth<<endl;
    }

    void render_circle(int radius) override{
        cout<<"Rendering raster circle: "<<radius<<endl;
    }
};