#include "Command.hpp"
#include "Light.hpp"

class LightOffCommand : public Command{
private:
    Light* light;
public:
    LightOffCommand(Light* light): light(light){}

    void execute() override{
        this->light->turn_off();
    }

    void undo() override{
        this->light->turn_on();
    }

    ~LightOffCommand(){
        delete this->light;
    }
};