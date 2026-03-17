#include "./headers/BankService.hpp"
#include "./headers/AtmMachine.hpp"

int main(){
    BankService& bank = BankService::get_instance();
    AtmMachine& atm = AtmMachine::get_instance();

    User* user = new User("Rohit" , "Rohit@mail.com");

    Account* account = bank.create_account(user);
    Card* card = bank.create_card(user->get_email() , account->get_account_number() , "1234");

    atm.insert_card(card);
    atm.select_operation(Operation::DEPOSIT);
    atm.insert_pin("1234");
    atm.insert_amount(20000);

    atm.insert_card(card);
    atm.select_operation(Operation::WITHDRAWAL);
    atm.insert_pin("1234");
    atm.insert_amount(12000);

    std::cout<<"Money Now: "<<account->get_amount()<<std::endl;
    return 0;
}