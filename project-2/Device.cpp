#include "Device.hpp"


#include <string>


Device::Device(std::string device_name,bool power_status) : device_name{device_name},power_status{power_status}{

}


Device::~Device(){

}


void Device::turnOn(){
    power_status=true;
}


void Device::turnOff(){
    power_status=false;
}

bool Device::showStatus()const{
    return power_status;
}


std::string Device::get_name()const{
    return device_name;
}


std::ostream& operator<<(std::ostream& os, const Device& device) {
    os<<"Device: "<<device.get_name()<<",Power Status "<<device.showStatus()<<std::endl;
    return os;
}
