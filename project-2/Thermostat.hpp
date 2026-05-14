#ifndef _THERMOSTAT_H_

#define _THERMOSTAT_H_
#include "Device.hpp"

class Thermostat : public Device{

    private:
        double temperature;



    public: 
        double get_temperature();
        Thermostat(double temperature,std::string thermostat_name);
};


#endif