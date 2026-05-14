#include "SecurityCamera.hpp"



std::string SecurityCamera::get_recording_status(){
    return recording_status;
}


SecurityCamera::SecurityCamera(std::string security_camera_name,std::string recording_status) : Device(security_camera_name) , recording_status{recording_status}{
    std::cout<<"Security Camera created with recording status " << recording_status <<"."<<std::endl;

}