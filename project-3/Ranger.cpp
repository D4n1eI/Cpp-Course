#include "Ranger.hpp"

float Ranger::calculatePower()
{
    return level * 12 + accuracy + health/2;
}


ClassName Ranger::getClassName() const{
    return ClassName::Ranger;
}

std::unique_ptr<GuildMember> Ranger::clone() const 
{
    return std::make_unique<Ranger>(*this);
}