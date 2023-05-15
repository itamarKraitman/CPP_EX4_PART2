#pragma once

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
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string, Point);
    };

    class YoungNinja : public Ninja
    {
    public:
        YoungNinja(string, Point);
    };

    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string, Point);
    };
}