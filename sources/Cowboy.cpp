#include "Cowboy.hpp"

namespace ariel
{
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), bullets(6)
    {
    }

    void Cowboy::shoot(Character *enemy)
    {
        enemy->hit(10);
    }

    bool Cowboy::hasboolets()
    {
        return false;
    }

    void Cowboy::reload()
    {
        this->bullets = 6;
    }

    string Cowboy::print()
    {
        return "";
    }

    int Cowboy::getAmoutOfBullets() const
    {
        return this->bullets;
    }

}