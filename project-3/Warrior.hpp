#include "GuildMember.hpp"
#include "ClassName.hpp"

class Warrior : public GuildMember
{

    friend std::ostream& operator<< (std::ostream& os, const Warrior& warrior){
        os << static_cast<const GuildMember&>(warrior);
        os << "║armor       ║║\n"<< warrior.armor<<std::endl;
        return os;

    }
private:
    int armor;

public:
    Warrior(int id, std::string name, int level, float health, int goldEarned, int armor)
        : GuildMember(id, name, level, health, goldEarned), armor{armor}
    {
    }

    virtual float calculatePower() override;
   
    virtual ClassName getClassName() const override;
    virtual std::unique_ptr<GuildMember> clone() const override;
    
    
};