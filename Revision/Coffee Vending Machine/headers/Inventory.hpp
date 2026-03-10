#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include "../enum.hpp"
#include <unordered_map>

class Inventory{
public:
    std::unordered_map<Ingredients , int> stock;
    
    void add_stock(Ingredients ingredient, int count);
    int get_count(Ingredients ingredient);
};

#endif