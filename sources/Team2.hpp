#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character * leader);

        void add(Character *character) override;
        void attack(Team *enemy) override;
    };
}

#endif //TEAM2_HPP
