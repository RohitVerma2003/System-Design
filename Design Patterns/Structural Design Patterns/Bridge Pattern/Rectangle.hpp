#include "./Interfaces/Shape.hpp"
#include "./Interfaces/Renderer.hpp"

class Rectangle : public Shape{
private:
    int length , breadth;
public:
    Rectangle(Renderer* renderer , int length , int breadth) : Shape(renderer) , length(length) , breadth(breadth) {}

    void draw() override{
        this->renderer->render_rectangle(this->length , this->breadth);
    }
};