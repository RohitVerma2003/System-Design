#ifndef ESPRESSO_HPP
#define ESPRESSO_HPP

#include "../../headers/Coffee.hpp"

class Espresso : public Coffee{
public:
    Espresso(std::string name, std::unordered_map<Ingredients, int> recipe, int price);
};

#endif