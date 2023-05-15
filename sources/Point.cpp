#include "Point.hpp"
#include <iostream>
#include <cmath>
using namespace std;

namespace ariel
{
    Point::Point() : xcr(0), ycr(0) {}

    Point::Point(double xcr, double ycr) : xcr(xcr), ycr(ycr) {}

    double Point::distance(Point p)
    {
        return (sqrt(pow((this->xcr - p.xcr), 2) + pow((this->ycr - p.ycr), 2)));
    }

    void Point::print()
    {
        cout << "(" << xcr << ", " << ycr << ")" << endl;
    }

    Point Point::moveTowards(Point other)
    {
        return other;
    }

    double Point::getX() const
    {
        return this->xcr;
    }

    double Point::getY() const
    {
        return this->ycr;
    }
}