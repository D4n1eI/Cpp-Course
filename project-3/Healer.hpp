#include "GuildMember.hpp"
#include "ClassName.hpp"

class Healer : public GuildMember
{

    friend std::ostream &operator<<(std::ostream &os, const Healer &healer)
    {
        os << static_cast<const GuildMember &>(healer);
        os << "║healingPower ║║\n" << healer.healingPower << std::endl;
        return os;
    }

private:
    int healingPower;

public:
    Healer(int id, std::string name, int level, float health, int goldEarned, int healingPower)
        : GuildMember(id, name, level, health, goldEarned), healingPower{healingPower}
    {
    }

    virtual float calculatePower() override;

    virtual ClassName getClassName() const override;
    virtual std::unique_ptr<GuildMember> clone() const override;
};