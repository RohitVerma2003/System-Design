#include "./Headers/Intersection.hpp"

int main(){
    Intersection* intersection = new Intersection();

    intersection->add_road("North" , 0 , 5 , 10);
    intersection->add_road("East" , 0 , 5 , 10);
    intersection->add_road("South" , 0 , 5 , 10);
    intersection->add_road("West" , 0 , 5 , 10);

    while(true) intersection->start();

    return 0;
}