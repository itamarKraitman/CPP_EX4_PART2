#ifndef TEAM_HPP
#define TEAM_HPP

#include "teamInterface.hpp"

namespace ariel
{
    class Team : public virtual teamInterface
    {

        std::vector<Cowboy *> cowboys;
        std::vector<Ninja *> ninjas;
        Character *leader;

    public:
        Team(Character * leader);
        void add(Character *character) override;
        void attack(teamInterface *enemy) override;
        int stillAlive() override;
        void print() override;
        vector<Character *> getSquad();
        int getSize();
    };
}

#endif // TEAM_HPP