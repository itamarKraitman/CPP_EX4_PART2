#include "Team.hpp"

namespace ariel
{
    Team::Team(Character *leader) : teamInterface(leader)
    {
        add(leader);
    }

    void Team::add(Character *newMember)
    {
        return;
    }

    void Team::attack(teamInterface *enemy)
    {
        return;
    }

    int Team::stillAlive()
    {
        return 0;
    }

    void Team::print()
    {
    }

    vector<Character *> Team::getSquad()
    {
        vector<Character *> squad;
        squad.insert(squad.end(), cowboys.begin(), cowboys.end());
        squad.insert(squad.end(), ninjas.begin(), ninjas.end());
        return squad;
    }

    int Team::getSize()
    {
        return this->getSquad().size();
    }

}