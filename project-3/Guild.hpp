#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include "GuildMember.hpp"
#include "Quest.hpp"
#include <map>
#include "ClassName.hpp"

class Guild
{
public:
    std::map<std::pair<int, std::string>, std::unique_ptr<GuildMember>> members;
    std::map<int, Quest> quests;


    void loadFromFile();

    void saveReport();

    void addMember(GuildMember & member);

    void removeMember(int id);

    GuildMember& findMemberById(int id);

    GuildMember& findMemberByName(std::string name);

    void displayMembers();

    void displayQuests();

    void assignQuest(Quest &quest, int id);

    GuildMember &findMemberByQuest(const Quest &quest);

    void completeQuest(Quest &quest);

    Quest &findQuestById(int id);

    void showStatistics();

    const GuildMember &getStrongestMember() const;

    double getAverageLevel() const;

    std::map<ClassName, int> getMembersPerClass() const;

    bool memberExists(int id) const;
    
    int getCompletedQuestCount() const;
};
