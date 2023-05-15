#include "Team2.hpp"
#include "Team.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
       add(leader);
    }

    void Team2::add(Character *character)
    {
        return;
    }

    void Team2::attack(Team *enemy)
    {
        return;
    }
}