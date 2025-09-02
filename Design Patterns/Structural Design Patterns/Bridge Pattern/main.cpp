#include "VectorRenderer.hpp"
#include "RasterRenderer.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"

int main(){
    VectorRenderer* vector = new VectorRenderer();
    RasterRenderer* raster = new RasterRenderer();

    Circle* circle = new Circle(vector , 10);
    Rectangle* rectangle = new Rectangle(raster , 2 , 3);

    circle->draw();
    rectangle->draw();

    delete vector;
    delete raster;
    delete circle;
    delete rectangle;
}