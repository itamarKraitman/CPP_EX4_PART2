#include "Team2.hpp"

namespace ariel
{
    Team2::Team2(Character *leader) : teamInterface(leader)
    {
        add(leader);
    }

    void Team2::add(Character *character)
    {
        return;
    }

    void Team2::attack(teamInterface *enemy)
    {
        return;
    }

    int Team2::stillAlive()
    {
        return this->squad.size();
    }

    void Team2::print()
    {
        return;
    }

    vector<Character *> Team2::getSquad()
    {
        return this->squad;
    }
    int Team2::getSize() const
    {
        return this->squad.size();
    }

}