#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include "./Road.hpp"

class Intersection{
public:
    std::vector<Road*> roads;
    int currentIndex;

    Intersection();
    void add_road(std::string name , int red , int yellow , int green);
    void start();
    void print_current_state();
};

#endif