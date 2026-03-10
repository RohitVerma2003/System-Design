#ifndef COFFEE_HPP
#define COFFEE_HPP

#include <string>
#include <unordered_map>
#include "../enum.hpp"

class Coffee{
public:
    std::string name;
    std::unordered_map<Ingredients , int> recipe;
    int price;
    
    Coffee();
    Coffee(std::string name , std::unordered_map<Ingredients , int> recipe , int price);
    std::string get_name();
    std::unordered_map<Ingredients , int> get_recipe();
    int get_price();
};

#endif