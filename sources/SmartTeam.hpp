#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "Team.hpp"
namespace ariel
{
    class SmartTeam : public Team
    {
    public:
        SmartTeam(Character *);
        void add(Character *newMember) override;
        void attack(Team *enemy) override;
        Character *pickVictim(Team *enemy) override;
        vector<Character*> sortSquad(vector<Character*> squad, auto victim);
    };
}

#endif // SMARTTEAM_HPP