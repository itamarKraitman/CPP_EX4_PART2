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

    Point Point::moveTowards(Point origin, Point destination, double dist)
    {
        double currentDistance = origin.distance(destination);

        if (currentDistance <= dist)
        {
            return destination;
        }

        double ratio = dist / currentDistance;
        double newX = origin.getX() + ratio * (destination.getX() - origin.getX());
        double newY = origin.getY() + ratio * (destination.getY() - origin.getY());

        Point closestPoint{newX, newY};
        return closestPoint;
    }

    double Point::getX() const
    {
        return this->xcr;
    }

    double Point::getY() const
    {
        return this->ycr;
    }

    void Point::setX(double xcr)
    {
        this->xcr = xcr;
    }

    void Point::setY(double ycr)
    {
        this->ycr = ycr;
    }
}