#pragma once

#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <vector>
using namespace std;

namespace ariel
{
    class teamInterface
    {
        Character *leader;

    public:
        teamInterface(Character *leader) : leader(leader) {}

        virtual void add(Character *) = 0;
        virtual void attack(teamInterface *) = 0;
        virtual int stillAlive() = 0;
        virtual void print() = 0;

        virtual ~teamInterface() = default;                       // destructor
        teamInterface(const teamInterface &) = delete;            // Copy constructor
        teamInterface &operator=(const teamInterface &) = delete; // Copy assignment operator
        teamInterface(teamInterface &&) = delete;                 // Move constructor
        teamInterface &operator=(teamInterface &&) = delete;      // Move assignment operator
    };
}