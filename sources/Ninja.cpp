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

    OldNinja::OldNinja(string name, Point location) : Ninja(name, location, 150, 8)
    {
    }

    YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 100, 14)
    {
    }

    TrainedNinja::TrainedNinja(string name, Point location) : Ninja(name, location, 120, 12)
    {
    }

}