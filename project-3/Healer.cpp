#include "Healer.hpp"

float Healer::calculatePower()
{
    return level * 11 + healingPower + health/3;
}


ClassName Healer::getClassName() const{
    return ClassName::Healer;
}

std::unique_ptr<GuildMember> Healer::clone() const 
{
    return std::make_unique<Healer>(*this);
}