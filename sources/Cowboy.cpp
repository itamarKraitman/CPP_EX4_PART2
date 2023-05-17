#include <iostream>
#include <sstream>
#include "Cowboy.hpp"

using namespace std;

using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110, 1), bullets(6)
    {
    }

    void Cowboy::shoot(Character *enemy)
    {

        if (this == enemy)
        {
            throw std::runtime_error("Character can't attack itself");
        }
        else if (enemy == nullptr)
        {
            throw std::invalid_argument("Null pointer");
        }

        else if (!this->isAlive())
        {
            throw std::runtime_error("Dead Cowboy cant shoot");
        }

        else if (!enemy->isAlive())
        {
            throw std::runtime_error("Attacking dead Character");
        }

        if (hasboolets()) // if has boolets, hit, otherwise, reload
        {
            cout << "enemy hit!" << endl;
            enemy->hit(10);
            this->bullets--;
        }
        else
        {
            cout << "cowboy has not bullets , reload" << endl;
            this->reload();
        }
    }

    bool Cowboy::hasboolets()
    {
        return this->bullets > 0;
    }

    void Cowboy::reload()
    {
        if (this->isAlive())
        {
            this->bullets = 6;
        }
        else
        {
            throw std::runtime_error("Dead cowboy can not reload");
        }
    }

    string Cowboy::print()
    {
        stringstream ss;
        if (this->isAlive())
        {
            ss << "C " << this->getName() << ", Point: <" << this->getLocation().getX() << "," << this->getLocation().getY() << ">"
                                                                                                                 ", Hit Points: "
               << this->getHitPoints() << endl;
        }
        else
        {
            ss << "C (" << this->getName() << "), Point: <" << this->getLocation().getX() << "," << this->getLocation().getY() << ">" << endl;
        }
        return ss.str();
    }

    int Cowboy::getAmoutOfBullets() const
    {
        return this->bullets;
    }

}