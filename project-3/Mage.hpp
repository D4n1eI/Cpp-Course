#include "GuildMember.hpp"
#include "ClassName.hpp"

class Mage : public GuildMember
{

    friend std::ostream& operator<< (std::ostream& os, const Mage& mage){
        os << static_cast<const GuildMember&>(mage);
        os << "║mana        ║║\n"<< mage.mana<<std::endl;
        return os;

    }
private:
    float mana;

public:
    Mage(int id, std::string name, int level, float health, int goldEarned, float mana)
        : GuildMember(id, name, level, health, goldEarned), mana{mana}
    {
    }

    virtual float calculatePower() override;
   
    virtual ClassName getClassName() const override;
    virtual std::unique_ptr<GuildMember> clone() const override;

};