#include <iostream>
#include "QuestStatus.hpp"
#include "Difficulty.hpp"

class GuildMember;

class Quest
{

    friend std::ostream &operator<<(std::ostream &os, const Quest &quest)
    {
        os << "\n║║Quest          ║║" << std::endl
           << "║id             ║║" << quest.id << std::endl
           << "║name           ║║" << quest.name << std::endl
           << "║difficulty     ║║" << quest.difficulty << std::endl
           << "║rewardGold     ║║" << quest.rewardGold << std::endl
           << "║requiredPower  ║║" << quest.requiredPower << std::endl
           << "║status         ║║" << quest.status << std::endl
           << "║assignedMember ║║" << quest.assignedMemberId << std::endl;

        return os;
    }

private:
    int id;
    std::string name;
    Difficulty difficulty;
    float rewardGold;
    float requiredPower;
    QuestStatus status;
    int assignedMemberId;

public:
    Quest(int id, std::string name, Difficulty difficulty, float rewardGold, float requiredPower, QuestStatus status, int assignedMemberId = 0);

    ~Quest() = default;
    void fail();
    void assign(int id);
    int getId();
    std::string getName();
    Difficulty getDifficulty();
    float getRewardGold();
    float getRequiredPower();
    QuestStatus getStatus() const;
    int getAssignedMemberId() const;
    void complete(GuildMember& member);
};