#include "./Interfaces/Shape.hpp"
#include "./Interfaces/Renderer.hpp"

class Circle : public Shape{
private:
    int radius;
public:
    Circle(Renderer* renderer , int radius) : Shape(renderer) , radius(radius) {}

    void draw() override{
        this->renderer->render_circle(this->radius);
    }
};