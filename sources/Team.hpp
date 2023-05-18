#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <vector>
#include <limits>

#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

namespace ariel
{
    using namespace std;

    class Team
    {
    private:
        Character *leader;
        vector<Character *> squad;
        int whichTypeOfTeam; // Team=1, Team2=2, Team3=3

    public:
        Team(Character *leader);

        virtual void add(Character *character);
        virtual void attack(Team *enemy);
        virtual int stillAlive();
        virtual void print();
        void setType(int type);
        int getType();
        vector<Character *> getSquad();
        void addToSquad(Character *newMember);
        int getSize();
        Character *getLeader();
        void setTeamLeader(Character *newLeader);
        void pickNewLeader();
        Character *pickVictim(Team *enemy);
        static bool compareCharacters(Character *first, Character *second);

        virtual ~Team();              // destructor
        Team(const Team &) = delete;            // Copy constructor
        Team &operator=(const Team &) = delete; // Copy assignment operator
        Team(Team &&) = delete;                 // Move constructor
        Team &operator=(Team &&) = delete;      // Move assignment operator
    };
}

#endif // TEAM_HPP