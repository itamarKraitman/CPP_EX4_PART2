#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include <iostream>

namespace ariel
{
    using namespace std;

     YoungNinja::YoungNinja(string name, Point location) : Ninja(name, location, 150, 8)
    {
    }
}