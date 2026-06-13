#pragma once
#include <string>
#include <stdexcept>

enum class Difficulty
{
    Easy,
    Medium,
    Hard,
    Extreme
};

inline Difficulty difficulty_from_string(const std::string& s)
{
    if (s == "Easy")    return Difficulty::Easy;
    if (s == "Medium")  return Difficulty::Medium;
    if (s == "Hard")    return Difficulty::Hard;
    if (s == "Extreme") return Difficulty::Extreme;

    throw std::invalid_argument("Invalid Difficulty: " + s);
}


inline std::ostream& operator<<(std::ostream& os, Difficulty d)
{
    switch (d)
    {
        case Difficulty::Easy:    return os << "Easy";
        case Difficulty::Medium:  return os << "Medium";
        case Difficulty::Hard:    return os << "Hard";
        case Difficulty::Extreme: return os << "Extreme";
        default: return os << "Unknown";
    }
}