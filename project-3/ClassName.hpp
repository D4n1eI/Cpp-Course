#pragma once

#include <iostream>
enum class ClassName
{
    Warrior,
    Mage,
    Ranger,
    Healer
};


inline std::ostream& operator<<(std::ostream& os, ClassName r)
{
    switch (r)
    {
        case ClassName::Warrior:  return os << "Warrior";
        case ClassName::Mage: return os << "Mage";
        case ClassName::Ranger:  return os << "Ranger";
        case ClassName::Healer:  return os << "Healer";
        default:             return os << "Unknown";
    }
}

inline ClassName stringToClassName(const std::string& str)
{
    if (str == "Warrior") return ClassName::Warrior;
    if (str == "Mage")    return ClassName::Mage;
    if (str == "Ranger")  return ClassName::Ranger;
    if (str == "Healer")  return ClassName::Healer;

    throw std::invalid_argument("Invalid class name: " + str);
}