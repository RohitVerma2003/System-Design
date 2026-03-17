#ifndef ATM_MACHINE_HPP
#define ATM_MACHINE_HPP

#include "../enum.hpp"
#include "../headers/BankService.hpp"

class AtmMachine{
private:
    AtmMachine();
    AtmMachine(const AtmMachine&) = delete;
    AtmMachine& operator=(const AtmMachine&) = delete;

    AtmState current_state;
    Operation operation;
    float amount;

    float inserted_amount;
    std::string inserted_pin;
    Card* inserted_card;

    BankService& bank = BankService::get_instance();
public:
    static AtmMachine& get_instance();

    void insert_card(Card* card);
    void select_operation(Operation op);
    void insert_pin(std::string pin);
    void insert_amount(float amout);
    void dispense_money(float amount);

    void set_to_idle();
};

#endif