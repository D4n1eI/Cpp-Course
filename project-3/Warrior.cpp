#include "Warrior.hpp"

float Warrior::calculatePower()
{
    return level * 10 + health + armor;
}

ClassName Warrior::getClassName() const
{
    return ClassName::Warrior;
}

std::unique_ptr<GuildMember> Warrior::clone() const 
{
    return std::make_unique<Warrior>(*this);
}