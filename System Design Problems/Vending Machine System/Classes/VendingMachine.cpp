#include "../Headers/VendingMachine.hpp"

VendingMachine::VendingMachine(): id(rand()) , current_state(MachineState::IDLE) , money(0){}

void VendingMachine::dispense_product(int slot){
    this->current_state = MachineState::DISPENSE;
    Product* product = this->products[slot][0];

    cout<<"Dispensing the product with ID: "<<product->get_product_id()<<endl;
    this->products[slot].erase(this->products[slot].begin());
}

void VendingMachine::dispense_change(int money){
    cout<<"Dispensing the amount: "<<money<<endl;
    this->money = 0;
    this->current_state = MachineState::IDLE;
}

bool VendingMachine::valid_amount(int slot){
    int product_price = this->products[slot][0]->get_price();
    return this->money >= product_price;
}

void VendingMachine::insert_money(int money){
    if(this->current_state == MachineState::DISPENSE){
        cout<<"The machine is in dispense state, cannot add money..."<<endl;
        return;
    }

    this->money += money;
    this->current_state = MachineState::MONEY_INSERTED;
}

void VendingMachine::select_product(int slot){
    if(this->money == 0){
        cout<<"Please insert the money first"<<endl;
        this->current_state = MachineState::IDLE;
        return;
    }

    if(this->products.find(slot) == this->products.end()){
        cout<<"Slot number is not valid..."<<endl;
        this->dispense_change(this->money);
        return;
    }

    if(this->products[slot].empty()){
        cout<<"The product is out of stock"<<endl;
        this->dispense_change(this->money);
        return;
    }

    if(this->valid_amount(slot)){
        int product_price = this->products[slot][0]->get_price();
        this->dispense_product(slot);
        this->dispense_change(this->money - product_price);
        return;
    }

    cout<<"Not valid amount"<<endl;
    this->dispense_change(this->money);
}

void VendingMachine::add_product(Product* product , int slot){
    this->products[slot].push_back(product);
}

void VendingMachine::remove_product(int slot){
    while(!this->products[slot].empty()){
        this->products[slot].pop_back();
    }
}

int VendingMachine::get_current_money(){
    return this->money;
}

MachineState VendingMachine::get_current_state(){
    return this->current_state;
}

int VendingMachine::get_id(){
    return this->id;
}