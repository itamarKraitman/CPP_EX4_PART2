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
        if (enemy == nullptr)
        {
            throw std::invalid_argument("Null pointer");
        }
        
        if (!this->isAlive())
        {
            throw std::runtime_error("Dead Cowboy cant shoot");
        }

        if (this == enemy)
        {
            throw std::runtime_error("Character can't attack itself");
        }

        if (!enemy->isAlive())
        {
            throw std::runtime_error("Attacking dead Character");
        }

        if (hasboolets) // if has boolets, hit, otherwise, reload
        {
            enemy->hit(10);
            this->bullets--;    
        }
        else
        {
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
            ss << "C " << this->name << ", Point: <" << this->location.getX() << "," << this->location.getY() << ">"
                                                                                                                 ", Hit Points: "
               << this->hitPoints << endl;
        }
        else
        {
            ss << "C (" << this->name << "), Point: <" << this->location.getX() << "," << this->location.getY() << ">" << endl;
        }
        return ss.str();
    }

    int Cowboy::getAmoutOfBullets() const
    {
        return this->bullets;
    }

    bool Cowboy::operator==(const Character &other) const
    {

        return this == &(static_cast<const Cowboy &>(other));
    }

    bool Cowboy::operator!=(const Character &other) const
    {

        return this != &(static_cast<const Cowboy &>(other));
    }

}