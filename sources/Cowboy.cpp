#include "Cowboy.hpp"
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


using namespace std;

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
        return this->bullets > 0;
    }

    void Cowboy::reload()
    {
        this->bullets = 6;
    }

    string Cowboy::print()
    {
        stringstream ss;
        ss << "C (" << this->name << "), Point: <" << this->location.getX() << "," << this->location.getY() << ">";
        if (this->isAlive())
        {
            ss <<  ", Hit Points: " << this->hitPoints << endl;
        }
        return ss.str();
    }

    int Cowboy::getAmoutOfBullets() const
    {
        return this->bullets;
    }

}