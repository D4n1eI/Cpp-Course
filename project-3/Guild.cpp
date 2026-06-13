#include "Guild.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include "Warrior.hpp"
#include "Healer.hpp"
#include "Ranger.hpp"
#include "Mage.hpp"
#include "QuestStatus.hpp"

void Guild::addMember(GuildMember &member)
{
    std::cout << "Adding member "
              << member
              << std::endl;
    members[{member.getId(), member.getName()}] = member.clone();
}

void Guild::removeMember(int id)
{
    std::cout<<"Removing member with id "<<id<<std::endl;
    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if (it->first.first == id)
        {
            members.erase(it);
            return;
        }
    }
}

GuildMember &Guild::findMemberById(int id)
{
    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if (it->first.first == id)
        {
            return *it->second;
        }
    }

    throw std::runtime_error("Member not found");
}

bool Guild::memberExists(int id) const
{
    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if (it->first.first == id)
        {
            return true;
        }
    }
    return false;
}

GuildMember &Guild::findMemberByName(std::string name)
{
    for (auto it = members.begin(); it != members.end(); ++it)
    {
        if (it->first.second == name)
        {
            return *it->second;
        }
    }

    throw std::runtime_error("Member not found");
}

void Guild::displayMembers()
{
    for (auto &m : members)
    {
        std::cout << *m.second;
    }
}

void Guild::displayQuests()
{
    for (auto &q : quests)
    {
        std::cout << q.second;
    }
}

void Guild::assignQuest(Quest &quest, int id)
{
    std::cout << "Assigned member with id "
              << id
              << " to quest "
              << quest.getName()
              << std::endl;
    quest.assign(id);
}

GuildMember &Guild::findMemberByQuest(const Quest &quest)
{
    if (quest.getAssignedMemberId() == 0)
    {
        throw std::runtime_error("Quest is not assigned to a member");
    }

    return findMemberById(quest.getAssignedMemberId());
}

void Guild::completeQuest(Quest &quest)
{
    GuildMember &member = findMemberByQuest(quest);

    if (member.calculatePower() >= quest.getRequiredPower())
    {
        quest.complete(member);
        return;
    }

    quest.fail();
}

Quest &Guild::findQuestById(int id)
{
    auto it = quests.find(id);
    if (it != quests.end())
    {
        return it->second;
    }

    throw std::runtime_error("Quest not found");
}

int Guild::getCompletedQuestCount() const
{
    return std::count_if(quests.begin(), quests.end(), [](const auto &quest)
                         { return quest.second.getStatus() == QuestStatus::Completed; });
}

const GuildMember &Guild::getStrongestMember() const
{
    if (members.empty())
    {
        throw std::runtime_error("No members in guild");
    }

    auto it = std::max_element(
        members.begin(),
        members.end(),
        [](const auto &a, const auto &b)
        {
            return a.second->calculatePower() < b.second->calculatePower();
        });

    return *(it->second);
}

double Guild::getAverageLevel() const
{
    if (members.empty())
    {
        return 0.0;
    }

    int totalLevel = 0;
    std::for_each(members.begin(), members.end(), [&totalLevel](const auto &member)
                  { totalLevel += member.second->getLevel(); });

    return static_cast<double>(totalLevel) / members.size();
}

std::map<ClassName, int> Guild::getMembersPerClass() const
{
    std::map<ClassName, int> counts{
        {ClassName::Warrior, 0},
        {ClassName::Mage, 0},
        {ClassName::Ranger, 0},
        {ClassName::Healer, 0},
    };

    std::for_each(members.begin(), members.end(), [&counts](const auto &member)
                  { ++counts[member.second->getClassName()]; });

    return counts;
}

void Guild::showStatistics()
{
    std::cout << "Guild Statistics" << std::endl;
    std::cout << "Total members: " << members.size() << std::endl;
    std::cout << "Total quests: " << quests.size() << std::endl;
    std::cout << "Average level: " << getAverageLevel() << std::endl;
    std::cout << "Completed quests: " << getCompletedQuestCount() << std::endl;

    std::cout << "Members per class:" << std::endl;
    const auto membersPerClass = getMembersPerClass();
    for (const auto &classCount : membersPerClass)
    {
        std::cout << classCount.first << ": " << classCount.second << std::endl;
    }

    if (!members.empty())
    {
        std::cout << "Strongest member:" << std::endl;
        std::cout << getStrongestMember() << std::endl;
    }
}

void Guild::saveReport()
{
    std::ofstream report("guild_report.txt");
    if (!report)
    {
        throw std::runtime_error("Unable to create report file");
    }

    report << "Guild Report" << std::endl;
    report << "============" << std::endl;
    report << "Total members: " << members.size() << std::endl;
    report << "Total quests: " << quests.size() << std::endl;
    report << "Average level: " << getAverageLevel() << std::endl;
    report << "Completed quests: " << getCompletedQuestCount() << std::endl;

    report << std::endl << "Members per class:" << std::endl;
    const auto membersPerClass = getMembersPerClass();
    for (const auto &classCount : membersPerClass)
    {
        report << classCount.first << ": " << classCount.second << std::endl;
    }

    if (!members.empty())
    {
        report << std::endl << "Strongest member:" << std::endl;
        report << getStrongestMember() << std::endl;
    }

    report << std::endl << "Members:" << std::endl;
    for (const auto &member : members)
    {
        report << *member.second << std::endl;
    }

    report << std::endl << "Quests:" << std::endl;
    for (const auto &quest : quests)
    {
        report << quest.second << std::endl;
    }

    std::cout << "Report saved to guild_report.txt" << std::endl;
}

void Guild::loadFromFile()
{
    std::cout << "Loading member data..." << std::endl;
    std::ifstream member_data("member_data.txt");
    if (!member_data)
    {
        throw std::runtime_error("Unable to open file");
    }
    std::string line;
    while (getline(member_data, line))
    {
        std::stringstream ss(line);
        std::string idText;
        std::string className;
        std::string name;
        std::string levelText;
        std::string healthText;
        std::string goldEarnedText;
        std::string specialAttributeText;

        if (!std::getline(ss, idText, '|') || !std::getline(ss, className, '|') || !std::getline(ss, name, '|') ||
            !std::getline(ss, levelText, '|') || !std::getline(ss, healthText, '|') || !std::getline(ss, goldEarnedText, '|') ||
            !std::getline(ss, specialAttributeText, '|'))
        {
            continue;
        }

        int id = std::stoi(idText);
        int level = std::stoi(levelText);
        int health = std::stoi(healthText);
        int goldEarned = std::stoi(goldEarnedText);
        int specialAttribute = std::stoi(specialAttributeText);

        if (className == "Warrior")
        {
            members[{id, name}] = std::make_unique<Warrior>(id, name, level, health, goldEarned, specialAttribute);
        }
        else if (className == "Mage")
        {
            members[{id, name}] = std::make_unique<Mage>(id, name, level, health, goldEarned, specialAttribute);
        }
        else if (className == "Ranger")
        {
            members[{id, name}] = std::make_unique<Ranger>(id, name, level, health, goldEarned, specialAttribute);
        }
        else if (className == "Healer")
        {
            members[{id, name}] = std::make_unique<Healer>(id, name, level, health, goldEarned, specialAttribute);
        }
        else
        {
            std::cout << "Unrecognized class name " << className << std::endl;
        }
    }
    std::cout << "Loaded member data." << std::endl;
    std::cout << "Loading quest data..." << std::endl;
    std::ifstream quest_data("quest_data.txt");
    if (!quest_data)
    {
        throw std::runtime_error("Unable to open file");
    }

    while (getline(quest_data, line))
    {
        std::stringstream ss(line);
        std::string idText;
        std::string name;
        std::string difficultyText;
        std::string powerText;
        std::string goldEarnedText;
        std::string statusText;

        if (!std::getline(ss, idText, '|') || !std::getline(ss, name, '|') ||
            !std::getline(ss, difficultyText, '|') || !std::getline(ss, powerText, '|') || !std::getline(ss, goldEarnedText, '|') ||
            !std::getline(ss, statusText, '|'))
        {
            continue;
        }

        int id = std::stoi(idText);
        float goldEarned = std::stof(goldEarnedText);
        float power = std::stof(powerText);
        Difficulty difficulty = difficulty_from_string(difficultyText);
        QuestStatus status = quest_status_from_string(statusText);
        quests.insert_or_assign(id, Quest{id, name, difficulty, goldEarned, power, status});
    }
    std::cout << "Loaded quest data." << std::endl;
}
