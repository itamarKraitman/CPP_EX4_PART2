#pragma once

namespace ariel
{
    class Point
    {
        double xcr;
        double ycr;

    public:
        Point();
        Point(double, double);
        double distance(Point);
        void print();
        Point moveTowards(Point);
        double getX() const;
        double getY() const;
    };

}