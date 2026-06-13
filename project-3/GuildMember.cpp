#include "GuildMember.hpp"
#include <iostream>

GuildMember::GuildMember(int id, std::string name, int level, int health, int goldEarned)
    : id{id}, name{name}, level{level}, health{health}, goldEarned{goldEarned}
{
}

int GuildMember::getId()
{
    return id;
}

std::string GuildMember::getName()
{
    return name;
}

int GuildMember::getLevel()
{
    return level;
}

int GuildMember::getHealth()
{
    return health;
}

void GuildMember::addGold(int amount)
{
    amount += amount;
}

void GuildMember::levelUp()
{
    level += 1;
}

int GuildMember::getGoldEarned(){
    return goldEarned;
}
