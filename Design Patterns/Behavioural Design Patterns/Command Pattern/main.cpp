#include "Light.hpp"
#include "Panel.hpp"
#include "Thermostat.hpp"
#include "LightOnCommand.hpp"
#include "LightOffCommand.hpp"
#include "ThermostatCommand.hpp"

int main(){
    Panel* panel = new Panel();

    Light* light = new Light();
    Thermostat* thermostat = new Thermostat();

    LightOnCommand* light_on = new LightOnCommand(light);
    LightOffCommand* light_off = new LightOffCommand(light);
    ThermostatCommand* thermostat_command = new ThermostatCommand(thermostat , 25 , 0);

    panel->set_command(light_on);
    panel->press();

    panel->set_command(light_off);
    panel->press();

    panel->set_command(thermostat_command);
    panel->press();

    panel->undo();

    delete panel;
    delete light;
    delete thermostat;
    delete light_on;
    delete light_off;
    delete thermostat_command;

    return -1;
}