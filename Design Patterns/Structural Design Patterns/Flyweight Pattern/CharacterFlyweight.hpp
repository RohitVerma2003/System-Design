#pragma once

class CharacterFlyweight{
public:
    virtual ~CharacterFlyweight(){}
    virtual void draw(int x , int y) = 0;
};