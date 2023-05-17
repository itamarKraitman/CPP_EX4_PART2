#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "Team.hpp"

namespace ariel
{
    using namespace std;

    class Team2 : public Team
    {
    public:
        Team2(Character * leader);

        void add(Character *newMember) override;
        void attack(Team *enemy) override;

    };
}

#endif //TEAM2_HPP
