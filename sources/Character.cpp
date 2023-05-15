#include "Character.hpp"
namespace ariel
{
    Character::Character() {}
    Character::Character(string name, Point location, int hitPoints) : name(name), location(location), hitPoints(hitPoints) {}

    bool Character::isAlive() const
    {
        return true;
    }

    double Character::distance(Character *other)
    {
        return this->location.distance(other->location);
    }

    string Character::getName() const
    {
        return this->name;
    }

    Point Character::getLocation() const
    {
        return this->location;
    }

    Point Character::setLocation(Point other)
    {
        this->location = other;
        return location;
    }

    int Character::getHitPoints() const
    {
        return this->hitPoints;
    }

    void Character::hit(int points)
    {
        this->hitPoints -= points;
    }

}