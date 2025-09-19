#include "../Headers/VendingMachine.hpp"

void print_machine_state(VendingMachine* machine){
    MachineState state = machine->get_current_state();

    switch(state){
        case MachineState::IDLE:
            cout<<"IDLE"<<endl;
            break;
        case MachineState::DISPENSE:
            cout<<"DISPENSE"<<endl;
            break;
        case MachineState::MONEY_INSERTED:
            cout<<"MONEY_INSERTED"<<endl;
            break;
    }
}

int main(){
    VendingMachine* machine = new VendingMachine();

    Product* p1 = new Product(1 , 100);
    Product* p2 = new Product(2 , 70);

    machine->add_product(p1 , 1);
    machine->add_product(p2 , 2);

    machine->insert_money(100);
    machine->select_product(1);

    machine->insert_money(100);
    machine->select_product(1);
    return 0;
}