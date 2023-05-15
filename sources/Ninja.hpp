#ifndef NINJA_HPP
#define NINJA_HPP

#include "Character.hpp"

namespace ariel
{
    class Ninja : public Character
    {
        int speed;

    public:
        Ninja(string, Point, int, int);
        virtual void move(const Character *other);
        virtual bool slash(Character *other);
        string print() override;
        int getSpeed() const;
    };
}

#endif // !NINJA_HPP
