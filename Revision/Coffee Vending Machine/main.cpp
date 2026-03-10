#include <iostream>
#include <unordered_map>

#include "./headers/VendingMachine.hpp"
#include "./headers/coffee/Espresso.hpp"
#include "./headers/coffee/Latte.hpp"

using namespace std;

int main() {

    VendingMachine* machine = new VendingMachine();

    unordered_map<Ingredients, int> espresso_recipe = {
        {Ingredients::WATER, 50},
        {Ingredients::BEANS, 18},
        {Ingredients::MILK, 100},
        {Ingredients::SUGAR, 5}
    };

    unordered_map<Ingredients, int> latte_recipe = {
        {Ingredients::WATER, 30},
        {Ingredients::MILK, 60},
        {Ingredients::BEANS, 18}
    };

    // Load ingredients
    machine->add_ingredient(Ingredients::WATER, 1000);
    machine->add_ingredient(Ingredients::MILK, 500);
    machine->add_ingredient(Ingredients::BEANS, 300);
    machine->add_ingredient(Ingredients::SUGAR, 200);

    // Create coffees
    Espresso espresso("Espresso", espresso_recipe, 50);
    Latte latte("Latte", latte_recipe, 80);

    // Register coffees
    machine->add_items("Espresso", 50);
    machine->add_items("Latte", 80);

    cout << "===== COFFEE VENDING MACHINE =====\n";

    while(true){

        cout << "\nAvailable Coffees\n";
        cout << "1. Espresso (50)\n";
        cout << "2. Latte (80)\n";
        cout << "3. Exit\n";

        int choice;
        cout << "\nSelect coffee: ";
        cin >> choice;

        Coffee selected;

        switch(choice){

            case 1:
                selected = espresso;
                break;

            case 2:
                selected = latte;
                break;

            case 3:
                cout << "Thank you for using the vending machine!\n";
                return 0;

            default:
                cout << "Invalid choice\n";
                continue;
        }

        // Select Coffee
        if(!machine->select_item(selected)){
            continue;
        }

        int money;
        cout << "Insert money: ";
        cin >> money;

        // Insert Money
        if(!machine->insert_money(money)){
            continue;
        }

        cout << "Processing your coffee...\n";

        // Dispense Coffee
        Coffee result = machine->dispense_coffee();

        cout << "Enjoy your " << result.get_name() << " ☕\n";
    }

    return 0;
}