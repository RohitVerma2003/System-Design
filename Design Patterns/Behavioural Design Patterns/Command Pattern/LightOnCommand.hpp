#include "Command.hpp"
#include "Light.hpp"

class LightOnCommand : public Command{
private:
    Light* light;
public:
    LightOnCommand(Light* light): light(light){}

    void execute() override{
        this->light->turn_on();
    }

    void undo() override{
        this->light->turn_off();
    }

    ~LightOnCommand(){
        delete this->light;
    }
};