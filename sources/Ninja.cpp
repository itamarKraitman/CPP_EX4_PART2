#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja(string name, Point location, int hitPoints, int speed) : Character(name, location, hitPoints), speed(speed)
    {
    }

    void Ninja::move(const Character *enemy)
    {
    }

    bool Ninja::slash(Character *enemy)
    {
        return true;
    }

    string Ninja::print()
    {
        return "";
    }

    int Ninja::getSpeed() const
    {
        return this->speed;
    }
}