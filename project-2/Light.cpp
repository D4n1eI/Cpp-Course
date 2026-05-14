#include "Light.hpp"

Light::Light(int brightness_level,std::string light_name)
    : Device{light_name}, brightness_level{brightness_level}
{
    std::cout<<"Light created with brightness level " << brightness_level <<"."<<std::endl;
}

int Light::get_brightness_level() {
    return brightness_level;
}