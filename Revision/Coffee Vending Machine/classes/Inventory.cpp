#include "../headers/Inventory.hpp"

void Inventory::add_stock(Ingredients ingredient, int count){
    this->stock[ingredient] += count;
}

int Inventory::get_count(Ingredients ingredient){return this->stock[ingredient];}
