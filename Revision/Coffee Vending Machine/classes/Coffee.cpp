#include "../headers/Coffee.hpp"

Coffee::Coffee(){
    this->name = "";
    this->price = 0;
}

Coffee::Coffee(std::string name, std::unordered_map<Ingredients, int> recipe, int price): name(name) , recipe(recipe) , price(price){}

std::string Coffee::get_name(){return this->name;}

std::unordered_map<Ingredients, int> Coffee::get_recipe(){return this->recipe;}

int Coffee::get_price(){return this->price;}
