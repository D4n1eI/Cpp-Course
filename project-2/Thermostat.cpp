#include "Thermostat.hpp"



double Thermostat::get_temperature(){
    return temperature;
}


Thermostat::Thermostat(double temperature, std::string thermostat_name):Device(thermostat_name),temperature{temperature}{
    std::cout<<"Thermostat created with brightness temperature " << temperature <<"ºC."<<std::endl;
}


