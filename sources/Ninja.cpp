#include "Ninja.hpp"
#include <iostream>
#include <sstream>

namespace ariel
{
    Ninja::Ninja(string name, Point location, int hitPoints, int speed) : Character(name, location, hitPoints, 2), speed(speed)
    {
    }

    void Ninja::move(const Character *enemy)
    {
        // calculate the distance between the ninja to the enemy
        double distanceBetween = this->location.distance(enemy->location);

        // if the distance is less or equal than the speed, stop at the same location as the enemy
        Point newLocation = Point::moveTowards(this->location, enemy->getLocation(), this->speed);
        this->location = newLocation;
    }

    bool Ninja::slash(Character *enemy)
    {
        if (this == enemy)
        {
            throw std::runtime_error("Character can't attack itself");
        }
        else if (enemy == nullptr)
        {
            throw std::invalid_argument("Null pointer passed");
        }

        if (!enemy->isAlive())
        {
            throw std::runtime_error("Enemy is dead!");
            return false;
        }
        if (!this->isAlive())
        {
            throw std::runtime_error("You are dead!");
            return false;
        }

        // if the enemy is far less than a meter, reduce its hitPoints by 40
        if (this->distance(enemy) < 1)
        {
            cout << "distance to enemy: " << this->distance(enemy) << endl;
            cout << enemy->getName() << " was hit by Ninja " << this->name << endl;
            enemy->hit(40);
            return true;
        }
        else
        {
            cout << "distance to enemy: " << this->distance(enemy) << endl;

            cout << enemy->getName() << " is too far! No damage was made by Ninja " << this->name << endl;
            return false;
        }
    }

    string Ninja::print()
    {
        stringstream ss;
        if (this->isAlive())
        {
            ss << "N " << this->name << ", Point: <" << this->location.getX() << "," << this->location.getY() << ">"
                                                                                                                 ", Hit Points: "
               << this->hitPoints << endl;
        }
        else
        {
            ss << "N (" << this->name << "), Point: <" << this->location.getX() << "," << this->location.getY() << ">" << endl;
        }
        return ss.str();
    }

    int Ninja::getSpeed() const
    {
        return this->speed;
    }

}