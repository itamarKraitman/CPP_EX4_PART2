#include "Team.hpp"
#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader)
    {
        add(leader);
    }

    void SmartTeam::add(Character *character)
    {
        return;
    }

    void SmartTeam::attack(Team *enemy)
    {
        return;
    }
}