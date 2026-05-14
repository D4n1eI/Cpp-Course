#ifndef _DEVICE_H_

#define _DEVICE_H_

#include <string>
#include <iostream>

class Device{
    private:
        std::string device_name;
        bool power_status;


    public:
        void turnOn();
        void turnOff();
        bool showStatus()const;
        std::string get_name()const;
        Device(std::string name,bool power_status = 0);
        ~Device();
        friend std::ostream& operator<< (std::ostream& os, const Device& device);    





};


#endif