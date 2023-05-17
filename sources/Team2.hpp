#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character * leader);

        void add(Character *newMember) override;
        void attack(Team *enemy) override;
        Character* pickTeamMember(Character* teamMember) override;
        int stillAlive() override;
        void print() override;

    };
}

#endif //TEAM2_HPP
