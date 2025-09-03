#include "CharacterFlyweight.hpp"
#include <string>
#include <iostream>
using namespace std;
#pragma once

class CharacterGlyph : public CharacterFlyweight{
private:
    char symbol;
    string font_family;
    string color;
    int font_size;

public:
    CharacterGlyph(char sym , string family , string color , int size): symbol(sym) , font_family(family) , color(color) , font_size(size){}

    void draw(int x , int y) override{
        cout<<"Drawing "<<this->symbol<<" in "<<this->font_family<<" with size "<<this->font_size<<" and color "<<this->color<<" at "<<x<<","<<y<<endl;
    }
};