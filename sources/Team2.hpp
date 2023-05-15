#ifndef TEAM2_HPP
#define TEAM2_HPP

#include "teamInterface.hpp"

namespace ariel
{
    class Team2 : public virtual teamInterface
    {
        std::vector<Character *> squad;
        Character *leader;

    public:
        Team2(Character * leader);

        void add(Character *character) override;
        void attack(teamInterface *enemy) override;
        int stillAlive() override;
        void print() override;
        vector<Character *> getSquad();
        int getSize() const;
    };
}

#endif //TEAM2_HPP
