#pragma once

#include <iostream>
#include <memory>

#include "ClassName.hpp"

class GuildMember
{
    friend std::ostream& operator<<(std::ostream& os, const GuildMember& guildMember)
    {
        os << "\n║Guild Member║║" << std::endl
           << "║id         ║║" << guildMember.id << std::endl
           << "║name       ║║" << guildMember.name << std::endl
           << "║level      ║║" << guildMember.level << std::endl
           << "║health     ║║" << guildMember.health << std::endl
           << "║goldEarned ║║" << guildMember.goldEarned << std::endl;
        os << "║class      ║║" << guildMember.getClassName() << std::endl;
        return os;
    }

protected:
    int id;
    std::string name;
    int level;
    int health;
    int goldEarned;

public:
    GuildMember(int id, std::string name, int level, int health, int goldEarned);
    virtual ~GuildMember() = default;
    virtual float calculatePower() = 0;
    virtual ClassName getClassName() const = 0;
    virtual std::unique_ptr<GuildMember> clone() const = 0;
    int getId();
    std::string getName();
    int getLevel();
    int getGoldEarned();
    int getHealth();
    void addGold(int amount);
    void levelUp();
};