#include "Mage.hpp"

float Mage::calculatePower()
{
    return level * 15 + mana;
}


ClassName Mage::getClassName() const{
    return ClassName::Mage;
}


std::unique_ptr<GuildMember> Mage::clone() const 
{
    return std::make_unique<Mage>(*this);
}