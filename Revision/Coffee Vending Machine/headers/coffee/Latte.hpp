#ifndef LATTE_HPP
#define LATTE_HPP

#include "../Coffee.hpp"

class Latte : public Coffee{
public:
    Latte(std::string name, std::unordered_map<Ingredients, int> recipe, int price);
};

#endif