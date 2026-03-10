#include "../../headers/coffee/Espresso.hpp"

Espresso::Espresso(std::string name, std::unordered_map<Ingredients, int> recipe, int price): Coffee(name , recipe , price){}