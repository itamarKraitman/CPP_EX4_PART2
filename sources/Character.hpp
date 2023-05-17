#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel
{
    class Character
    {

    public:
        Point location;
        int hitPoints;
        string name;
        int ninjaOrCowboy; // cowboy = 1, ninja = 2
        bool assignedToTeam;

        Character();
        Character(string name, Point po, int hp, int ninjaOrCowboy);

        bool isAlive() const;
        double distance(Character *);
        string getName() const;
        Point getLocation() const;
        Point setLocation(Point other);
        int getHitPoints() const;
        void hit(int points);
        int isNinjaOrCowboy();
        bool isDead();
        void assignToTeam();
        bool isAssignedToTeam();
        virtual string print() = 0;

        virtual ~Character() = default;                   // destructor
        Character(const Character &) = delete;            // Copy constructor
        Character &operator=(const Character &) = delete; // Copy assignment operator
        Character(Character &&) = delete;                 // Move constructor
        Character &operator=(Character &&) = delete;      // Move assignment operator
    };

}
#endif