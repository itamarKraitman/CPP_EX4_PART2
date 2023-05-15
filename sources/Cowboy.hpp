#pragma once
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
        int bullets;

    public:
        Cowboy(string, Point);
        void shoot(Character *other);
        bool hasboolets();
        void reload();
        string print() override;
        int getAmoutOfBullets() const;
    };
}