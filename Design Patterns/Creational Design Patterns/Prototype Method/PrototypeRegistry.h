#include<map>
#include "Enemy.h"
using namespace std;

class PrototypeRegistry{
private:
    map<string , Enemy*> prototypes;
public:
    void register_prototype(string key , Enemy* enemy){
        this->prototypes[key] = enemy;
    }

    Enemy* get(string key){
        if(this->prototypes.find(key) != this->prototypes.end()){
            return this->prototypes[key]->clone();
        }

        throw invalid_argument("No Prototype found");
    }

    ~PrototypeRegistry(){
        for(auto& enemy : this->prototypes){
            delete enemy.second;
        }
    }
};