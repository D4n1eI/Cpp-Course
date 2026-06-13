#include "GuildMember.hpp"
#include "ClassName.hpp"

class Ranger : public GuildMember
{

    friend std::ostream& operator<< (std::ostream& os, const Ranger& ranger){
        os << static_cast<const GuildMember&>(ranger);
        os << "║accuracy     ║║\n"<< ranger.accuracy<<std::endl;
        return os;

    }


private:
    int accuracy;

public:
    Ranger(int id, std::string name, int level, float health, int goldEarned, int accuracy)
        : GuildMember(id, name, level, health, goldEarned), accuracy{accuracy}
    {
    }

    virtual float calculatePower() override;
   
    virtual ClassName getClassName() const override;
    virtual std::unique_ptr<GuildMember> clone() const override;

};