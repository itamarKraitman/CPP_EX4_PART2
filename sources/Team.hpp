#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>
#include <limits>

#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
    using namespace std;

    class Team
    {

    public:
        vector<Cowboy *> cowboys;
        vector<Ninja *> ninjas;
        Character *leader;
        vector<Character *> squad;
        Team(Character *leader);
        virtual void add(Character *character);
        virtual void attack(Team *enemy);
        int stillAlive();
        void print();
        vector<Character *> getSquad();
        int getSize();
        Character *getLeader();
        void setTeamLeader(Character *newLeader);
        Character* pickTeamMember(Character* teamMember);

        virtual ~Team() = default;              // destructor
        Team(const Team &) = delete;            // Copy constructor
        Team &operator=(const Team &) = delete; // Copy assignment operator
        Team(Team &&) = delete;                 // Move constructor
        Team &operator=(Team &&) = delete;      // Move assignment operator
    };
}

#endif // TEAM_HPP