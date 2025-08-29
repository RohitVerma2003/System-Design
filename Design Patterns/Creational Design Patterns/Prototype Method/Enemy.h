#pragma once
#include<iostream>
#include <string>
#include "IPrototype.h"
using namespace std;

class Enemy : public IPrototype{
private:
    string type;
    int health;
    bool armoured;
    double speed;
    string weapon;
public:
    Enemy(string type , int health , bool armoured , double speed , string weapon) : type(type) , health(health) , armoured(armoured) , speed(speed) , weapon(weapon) {}

    Enemy* clone() override{
        return new Enemy(this->type , this->health , this->armoured , this->speed , this->weapon);
    }

    void setHealth(int hp){
        this->health = hp;
    }

    void print_stats(){
        cout<<type<<"[Health: "<<this->health<<" Is Armoured: "<<this->armoured<<" Speed: "<<this->speed<<" Weapon: "<<this->weapon<<"]"<<endl;
    }
};