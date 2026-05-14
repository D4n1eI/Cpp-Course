#include "Device.hpp"

#include "Light.hpp"

#include "SecurityCamera.hpp"

#include "Thermostat.hpp"

#include <iostream>

#include <string>

#include <vector>



int main(){
    std::vector<Device*> devices{};

    bool proceed = true;

    while(proceed){
        std::cout<<"1. Add Light         "<<std::endl;
        std::cout<<"2. Add Thermostat    "<<std::endl;
        std::cout<<"3. Add Camera        "<<std::endl;
        std::cout<<"4. Show Devices      "<<std::endl;
        std::cout<<"5. Turn Device On    "<<std::endl;
        std::cout<<"6. Turn Device Off   "<<std::endl;
        std::cout<<"7. Exit              "<<std::endl;
        int response{};
        std::cin>>response;

        switch (response)
        {
        case 1:
            {
                Light* light = new Light(50,"Light1");
                devices.push_back(light);
                break;
            }

        case 2:
            {
                Thermostat* thermostat = new Thermostat(35.0,"Thermostat1");
                devices.push_back(thermostat);
                break;
            }
        
        case 3:
            {
                SecurityCamera* security_camera = new SecurityCamera("SecurityCamera1");
                devices.push_back(security_camera);
                break;
            }

        case 4:
            {
                for (Device* d : devices){
                    std::cout << *d << std::endl;
                }
                break;
            }

        case 5:
            {
                std::cout<<"Device name? ";
                std::string device_name{};
                std::cin >> device_name;

                for (Device* d : devices){
                    if (d->get_name()==device_name){
                        d->turnOn();
                        std::cout<<"Turned on "<<d->get_name()<<std::endl;
                    }
                }
                break;
            }

        case 6:
            {
                std::cout<<"Device name? ";
                std::string device_name{};
                std::cin >> device_name;

                for (Device* d : devices){
                    if (d->get_name()==device_name){
                        d->turnOff();
                        std::cout<<"Turned on "<<d->get_name()<<std::endl;
                    }
                }
                break;
            }

        case 7:
            {
                std::cout<<"Exiting..."<<std::endl;
                for (Device* d : devices){
                    delete d;
                }
                proceed=false;
                break;
            }
           
        default:
            break;
        }
    }




    return 0;
}