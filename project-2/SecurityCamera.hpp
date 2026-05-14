#ifndef _SECURITY_CAMERA_H_

#define _SECURITY_CAMERA_H_
#include "Device.hpp"

class SecurityCamera : public Device{

    private:
        std::string recording_status;


    public: 
        std::string get_recording_status();
        SecurityCamera(std::string security_camera_name,std::string recording_status = "Okay");

};


#endif