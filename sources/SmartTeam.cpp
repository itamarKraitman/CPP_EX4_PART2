#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : teamInterface(leader)
    {
        add(leader);
    }

    void SmartTeam::add(Character *character)
    {
        return;
    }

    void SmartTeam::attack(teamInterface *enemy)
    {
        return;
    }

    int SmartTeam::stillAlive()
    {
        return this->squad.size();
    }

    void SmartTeam::print()
    {
        return;
    }

    vector<Character *> SmartTeam::getEnemy(SmartTeam *enemy)
    {
        return enemy->squad;
    }

    vector<Character *> SmartTeam::getSquad()
    {
        return this->squad;
    }

    int SmartTeam::getSize()
    {
        return this->squad.size();
    }

}