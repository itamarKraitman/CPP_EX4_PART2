#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"
namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *);
        void add(Character *character) override;
        void attack(Team *enemy) override;
    };
}

#endif // SMARTTEAM_HPP