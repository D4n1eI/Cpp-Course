#include "Quest.hpp"
#include "GuildMember.hpp"
Quest::Quest(int id, std::string name, Difficulty difficulty, float rewardGold, float requiredPower, QuestStatus status, int assignedMemberId)
    : id{id}, name{name}, difficulty{difficulty}, rewardGold{rewardGold}, requiredPower{requiredPower}, status{status}, assignedMemberId{assignedMemberId}
{
}

void Quest::complete(GuildMember& member)
{
    std::cout << "Hooray! Quest by the name of "
              << name
              << " was just completed. Congratulations!"
              << " You are awarded "
              << rewardGold
              << " pieces of gold!"
              << std::endl;

    member.addGold(rewardGold);

    status = QuestStatus::Completed;
}

void Quest::fail()
{
    std::cout << "Quest by the name of "
              << name
              << " has failed."
              << std::endl;
    status = QuestStatus::Failed;
}


void Quest::assign(int id){
    assignedMemberId = id;
    status = QuestStatus::Assigned;
}

int Quest::getId(){
    return id;
}

std::string Quest::getName(){
    return name;
}


Difficulty Quest::getDifficulty(){
    return difficulty;
}

float Quest::getRewardGold(){
    return rewardGold;
}


float Quest::getRequiredPower(){
    return requiredPower;
}

QuestStatus Quest::getStatus() const{
    return status;
}

int Quest::getAssignedMemberId() const{
    return assignedMemberId;
}

