#include "PrototypeRegistry.h"
#include "Enemy.h"
#include<iostream>
using namespace std;

class Game{
public:
    static void main(){
        PrototypeRegistry registry;

        registry.register_prototype("Flying" , new Enemy("Flying Enemy" , 10 , false , 10 , "Blast"));
        registry.register_prototype("Armoured" , new Enemy("Armoured Enemy" , 20 , true , 5 , "Sword"));

        Enemy* e1 = registry.get("Flying");
        Enemy* e2 = registry.get("Armoured");
        Enemy* e3 = registry.get("Armoured");
        
        e2->setHealth(10);
        e1->print_stats();
        e2->print_stats();
        e3->print_stats();


        cout<<e2<<" "<<e3<<endl;

        delete e1;
        delete e2;
    }
};

int main(){
    Game::main();
    return -1;
}