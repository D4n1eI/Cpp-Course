#ifndef _LIGHT_H_

#define _LIGHT_H_
#include "Device.hpp"

class Light : public Device{

    private:
        int brightness_level;



    public: 
        int get_brightness_level();
        Light(int brightness_level,std::string light_name);
};


#endif