#include "./Product.hpp"
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

enum class MachineState{
    IDLE , MONEY_INSERTED , DISPENSE
} ;

class VendingMachine{
private:
    int id;
    unordered_map<int , vector<Product*>> products;
    MachineState current_state;
    int money;

    void dispense_product(int slot);
    void dispense_change(int money);
    bool valid_amount(int slot);
public:
    VendingMachine();
    void insert_money(int money);
    void select_product(int slot);
    void add_product(Product* product , int slot);
    void remove_product(int slot);

    MachineState get_current_state();
    int get_current_money();
    int get_id();
};