#include "../Headers/Product.hpp"

Product::Product(int slot , int price): product_id(rand()) , slot_number(slot) , price(price){}

int Product::get_price(){
    return this->price;
}

int Product::get_product_id(){
    return this->product_id;
}

int Product::get_slot_number(){
    return this->slot_number;
}