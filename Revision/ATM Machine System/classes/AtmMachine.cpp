#include "../headers/AtmMachine.hpp"

AtmMachine::AtmMachine() {}

AtmMachine &AtmMachine::get_instance(){
    static AtmMachine instance;
    return instance;
}

void AtmMachine::insert_card(Card *card){
    if(this->current_state != AtmState::IDLE){
        std::cout<<"Machine is not idle"<<std::endl;
        this->set_to_idle();
        return;
    }

    this->inserted_card = card;
    this->current_state = AtmState::SELECT_OPERATION;
    std::cout<<"Card Inserted"<<std::endl;
}

void AtmMachine::select_operation(Operation op){
    if(this->current_state != AtmState::SELECT_OPERATION){
        std::cout<<"Machine is not in select operation state"<<std::endl;
        this->set_to_idle();
        return;
    }

    this->operation = op;
    this->current_state = AtmState::INSERT_PIN;
    std::cout<<"Operation Selected"<<std::endl;
}

void AtmMachine::insert_pin(std::string pin){
    if(this->current_state != AtmState::INSERT_PIN){
        std::cout<<"Machine is not in insert pin state"<<std::endl;
        this->set_to_idle();
        return;
    }

    this->inserted_pin = pin;
    std::cout<<"Pin inserted: "<<this->inserted_pin<<std::endl;

    if(!this->bank.validate_card_pin(this->inserted_card->get_card_number() , this->inserted_pin)){
        std::cout<<"Pin is invalid"<<std::endl;
        this->set_to_idle();
        return;
    }

    this->current_state = AtmState::INSERT_AMOUNT;
    std::cout<<"Pin is valid"<<std::endl;
}

void AtmMachine::insert_amount(float amount){
    if(this->current_state != AtmState::INSERT_AMOUNT){
        std::cout<<"Machine is not in insert amount state"<<std::endl;
        this->set_to_idle();
        return;
    }

    this->inserted_amount = amount;

    if(this->operation == Operation::DEPOSIT){
        this->bank.deposit_amount(this->inserted_card->get_account_number() , amount);
        this->amount += amount;

        std::cout<<"Money Deposited: "<<this->inserted_amount<<std::endl;
    }else{
        if(this->amount < amount){
            std::cout<<"Insufficient money in the ATM"<<std::endl;
            this->set_to_idle();
            return;
        }

        Account* account = this->bank.get_account(this->inserted_card->get_account_number());

        if(!account || account->get_amount() < this->inserted_amount){
            std::cout<<"Invalid Account or Insufficient money in the account"<<std::endl;
            this->set_to_idle();
            return;
        }

        this->bank.withdraw_amount(account->get_account_number() , this->inserted_amount);
        this->dispense_money(this->inserted_amount);
    }
    this->set_to_idle();
}

void AtmMachine::dispense_money(float amount){
    this->current_state = AtmState::DISPENSING;
    std::cout<<"Dispensing Money: "<<this->inserted_amount<<std::endl;

    this->amount -= this->inserted_amount;
}

void AtmMachine::set_to_idle(){
    this->inserted_amount = 0;
    this->inserted_pin = "";
    this->inserted_card = NULL;

    this->current_state = AtmState::IDLE;
    std::cout<<"Machine is now in Idle state"<<std::endl;
}
