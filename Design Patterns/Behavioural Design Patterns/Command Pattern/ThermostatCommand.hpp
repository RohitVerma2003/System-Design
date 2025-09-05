#include "Command.hpp"
#include "Thermostat.hpp"

class ThermostatCommand : public Command{
private:
    Thermostat* thermostat;
    int new_temperature;
    int prev_temperature;
public:
    ThermostatCommand(Thermostat* thermo , int new_temp , int prev_temp): thermostat(thermo) , new_temperature(new_temp) , prev_temperature(prev_temp){}

    void execute() override{
        this->prev_temperature = this->thermostat->get_temperature();
        this->thermostat->set_temperature(this->new_temperature);
    }

    void undo() override{
        this->thermostat->set_temperature(prev_temperature);
    }
};