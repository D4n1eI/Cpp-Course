#pragma once
#include <string>
#include <cctype>
#include <stdexcept>

enum class QuestStatus
{
    Available,
    Assigned,
    Completed,
    Failed
};

inline std::string trim_copy(const std::string& s)
{
    const auto first = s.find_first_not_of(" \t\n\r\f\v");
    if (first == std::string::npos)
    {
        return "";
    }

    const auto last = s.find_last_not_of(" \t\n\r\f\v");
    return s.substr(first, last - first + 1);
}

inline QuestStatus quest_status_from_string(const std::string& s)
{
    const std::string value = trim_copy(s);

    if (value == "Available") return QuestStatus::Available;
    if (value == "Assigned")  return QuestStatus::Assigned;
    if (value == "Completed") return QuestStatus::Completed;
    if (value == "Failed")    return QuestStatus::Failed;

    throw std::invalid_argument("Invalid Status: " + value);
}

inline std::ostream& operator<<(std::ostream& os, QuestStatus s)
{
    switch (s)
    {
        case QuestStatus::Available: return os << "Available";
        case QuestStatus::Assigned:   return os << "Assigned";
        case QuestStatus::Completed:  return os << "Completed";
        case QuestStatus::Failed:     return os << "Failed";
        default: return os << "Unknown";
    }
}