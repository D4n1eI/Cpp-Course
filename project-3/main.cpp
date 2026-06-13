#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>
#include "Guild.hpp"
#include "ClassName.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Ranger.hpp"
#include "Healer.hpp"

void recruitMember(Guild &guild)
{
    std::cout << "Recruiting Member..." << std::endl;

    std::string idstr{};
    std::string name{};
    std::string levelstr{};
    std::string healthstr{};
    std::string goldEarnedstr{};
    int id;

    while (true)
    {
        std::cout << "Id?" << std::endl;
        std::cin >> idstr;

        id = std::stoi(idstr);

        try
        {
            guild.findMemberById(id);

            std::cout << "A member with that ID already exists. Please choose another ID." << std::endl;
        }
        catch (const std::runtime_error &)
        {
            break;
        }
    }

    std::cout << "Name?";
    std::cin >> name;

    std::cout << "Level?";
    std::cin >> levelstr;
    int level = std::stoi(levelstr);

    std::cout << "Health?";
    std::cin >> healthstr;
    float health = std::stof(healthstr);

    std::cout << "Gold Earned?";
    std::cin >> goldEarnedstr;
    int gold = std::stoi(goldEarnedstr);

    std::cout << "Class(Warrior,Mage,Ranger,Healer)?";
    std::string className{};
    std::cin >> className;

    ClassName cls = stringToClassName(className);

    switch (cls)
    {
    case ClassName::Warrior:
    {
        std::cout << "Armor?";
        std::string armorstr{};
        std::cin >> armorstr;
        int armor = std::stoi(armorstr);
        Warrior warrior = Warrior{id, name, level, health, gold, armor};
        guild.addMember(warrior);
        break;
    }
    case ClassName::Mage:
    {
        std::cout << "Mana?";
        std::string manastr{};
        std::cin >> manastr;
        float mana = std::stof(manastr);
        Mage mage = Mage{id, name, level, health, gold, mana};
        guild.addMember(mage);
        break;
    }

    case ClassName::Ranger:
    {
        std::cout << "Accuracy?";
        std::string accuracystr{};
        std::cin >> accuracystr;
        int accuracy = std::stoi(accuracystr);
        Ranger ranger = Ranger{id, name, level, health, gold, accuracy};
        guild.addMember(ranger);
        break;
    }
    case ClassName::Healer:
    {
        std::cout << "Healing Power?";
        std::string healingpowerstr{};
        std::cin >> healingpowerstr;
        int healingPower = std::stoi(healingpowerstr);
        Healer healer = Healer{id, name, level, health, gold, healingPower};
        guild.addMember(healer);
        break;
    }

    default:
        break;
    }
}

int main()
{
    bool proceed = true;
    Guild guild = Guild{};
    while (proceed)
    {
        std::cout << "1. Load Data" << std::endl;
        std::cout << "2. View Members" << std::endl;
        std::cout << "3. View Quests" << std::endl;
        std::cout << "4. Assign Quest" << std::endl;
        std::cout << "5. Complete Quest" << std::endl;
        std::cout << "6. Recruit Member" << std::endl;
        std::cout << "7. Remove Member" << std::endl;
        std::cout << "8. Search Member" << std::endl;
        std::cout << "9. Guild Statistics" << std::endl;
        std::cout << "10.Save Report" << std::endl;
        std::cout << "0. Exit" << std::endl;

        int choice{};
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            guild.loadFromFile();
            break;
        }

        case 2:
        {
            guild.displayMembers();
            break;
        }
        case 3:
            guild.displayQuests();
            break;
        case 4:
        {
            std::cout << "Quest id?";
            std::string questResponse{};
            std::cin >> questResponse;
            Quest &quest = guild.findQuestById(std::stoi(questResponse));
            std::cout << "Member id?";
            std::string memberResponse{};
            std::cin >> memberResponse;
            guild.assignQuest(quest, std::stoi(memberResponse));
            break;
        }
        case 5:
        {
            std::cout << "Quest id?";
            std::string questResponse{};
            std::cin >> questResponse;
            Quest &quest = guild.findQuestById(std::stoi(questResponse));
            guild.completeQuest(quest);
            break;
        }
        case 6:
        {
            recruitMember(guild);
            break;
        }
        case 7:
        {
            std::cout << "Removing member..." << std::endl;
            std::cout << "Member Id?";
            int id;
            std::cin >> id;
            guild.removeMember(id);
        }
        break;
        case 8:
        {
            std::cout << "Looking for member..." << std::endl;
            std::cout << "Member Id? ";

            int id;
            std::cin >> id;

            try
            {
                GuildMember &m = guild.findMemberById(id);
                std::cout << m;
            }
            catch (const std::runtime_error &e)
            {
                std::cout << e.what() << std::endl;
            }

            break;
        }

        case 9:
        {
            guild.showStatistics();
            break;
        }

        case 10:
        {
            guild.saveReport();
            break;
        }
        case 0:
            proceed = false;
            break;

        default:
            break;
        }
    }

    return 0;
}
