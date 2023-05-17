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
        double distanceBetween = this->getLocation().distance(enemy->getLocation());

        // if the distance is less or equal than the speed, stop at the same location as the enemy
        Point newLocation = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->speed);
        this->setLocation(newLocation);
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
            cout << enemy->getName() << " was hit by Ninja " << this->getName() << endl;
            enemy->hit(40);
            return true;
        }
        else
        {
            cout << "distance to enemy: " << this->distance(enemy) << endl;

            cout << enemy->getName() << " is too far! No damage was made by Ninja " << this->getName() << endl;
            return false;
        }
    }

    string Ninja::print()
    {
        stringstream ss;
        if (this->isAlive())
        {
            ss << "N " << this->getName() << ", Point: <" << this->getLocation().getX() << "," << this->getLocation().getY() << ">"
                                                                                                                 ", Hit Points: "
               << this->getHitPoints() << endl;
        }
        else
        {
            ss << "N (" << this->getName() << "), Point: <" << this->getLocation().getX() << "," << this->getLocation().getY() << ">" << endl;
        }
        return ss.str();
    }

    int Ninja::getSpeed() const
    {
        return this->speed;
    }

}