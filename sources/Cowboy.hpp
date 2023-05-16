#ifndef COWBOY_HPP
#define COWBOY_HPP


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

        bool operator==(const Character& other) const;
        bool operator!=(const Character& other) const;
    };
}

#endif // !COWBOY_HPP
