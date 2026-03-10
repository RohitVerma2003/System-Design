#ifndef VENDING_MACHINE_HPP
#define VENDING_MACHINE_HPP

#include "./Inventory.hpp"
#include "Coffee.hpp"
#include <iostream>

class VendingMachine{
public:
    Inventory* inventory;
    VendingMachineState state;
    std::unordered_map<std::string , int> items;
    Coffee selected_coffee;
    int inserted_money;

    VendingMachine();

    void add_ingredient(Ingredients ingredient , int count);

    void set_state(VendingMachineState state);

    void add_items(std::string coffee , int price);

    bool select_item(Coffee coffee);

    bool insert_money(int money);

    Coffee dispense_coffee();

    int dispense_money();
};

#endif