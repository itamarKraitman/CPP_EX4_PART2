#ifndef SMARTTEAM_HPP
#define SMARTTEAM_HPP

#include "teamInterface.hpp"

namespace ariel
{
    class SmartTeam : public virtual teamInterface
    {
        std::vector<Character *> squad;
        Character *leader;

    public:
        SmartTeam(Character *);
        void add(Character *character) override;
        void attack(teamInterface *enemy) override;
        int stillAlive() override;
        void print() override;
        vector<Character *> getEnemy(SmartTeam *);
        vector<Character *> getSquad();
        int getSize();
    };
}

#endif // SMARTTEAM_HPP