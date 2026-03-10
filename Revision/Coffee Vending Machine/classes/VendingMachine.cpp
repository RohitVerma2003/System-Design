#include "../headers/VendingMachine.hpp"

VendingMachine::VendingMachine(){
    this->inventory = new Inventory();
    this->state = VendingMachineState::IDLE;
}

void VendingMachine::add_ingredient(Ingredients ingredient, int count){
    this->inventory->add_stock(ingredient , count);
}

void VendingMachine::set_state(VendingMachineState state){
    this->state = state;
}

void VendingMachine::add_items(std::string coffee, int price){
    this->items[coffee] = price;
}

bool VendingMachine::select_item(Coffee coffee){
    if(this->state != VendingMachineState::IDLE){
        std::cout<<"Vending Machine Is Not Idle"<<std::endl;
        return false;
    }

    this->set_state(VendingMachineState::SELECT_COFFEE);

    for(auto item : coffee.get_recipe()){
        Ingredients ingredient = item.first;
        int count = item.second;

        if(this->inventory->get_count(ingredient) < count){
            std::cout<<"Sorry the ingredients are not sufficient for this product..."<<std::endl;
            this->set_state(VendingMachineState::IDLE);
            return false;
        }
    }

    this->set_state(VendingMachineState::INSERT_MONEY);
    this->selected_coffee = coffee;
    std::cout<<"Coffee Selected -> "<<this->selected_coffee.get_name()<<std::endl;
    return true;
}

bool VendingMachine::insert_money(int money){
    if(this->state != VendingMachineState::INSERT_MONEY){
        std::cout<<"Vending Machine Is Not In Insert Money State"<<std::endl;
        return false;
    }

    if(this->selected_coffee.get_price() > money){
        std::cout<<"Money Is not Sufficient..."<<std::endl;
        this->set_state(VendingMachineState::DISPENSE);
        this->dispense_money(money);
        this->set_state(VendingMachineState::IDLE);
        return false;
    }

    this->set_state(VendingMachineState::PROCESSING);
    this->inserted_money = money;
    return true;
}

Coffee VendingMachine::dispense_coffee(){
    std::cout<<"Dispensing....."<<std::endl;
    this->set_state(VendingMachineState::DISPENSE);
    this->dispense_money();

    Coffee result = this->selected_coffee;
    this->selected_coffee = Coffee();

    std::cout<<"Dispensed Coffee -> "<<result.get_name()<<std::endl;
    this->set_state(VendingMachineState::IDLE);
    return result;
}

int VendingMachine::dispense_money(){
    int result = this->inserted_money - this->selected_coffee.get_price();
    this->inserted_money = 0;
    std::cout<<"Dispensed Money -> "<<result<<std::endl;
    return result;
}

int VendingMachine::dispense_money(int price){
    std::cout<<"Dispensed Money -> "<<price<<std::endl;
    return price;
}
