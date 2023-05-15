#ifndef POINT_HPP
#define POINT_HPP

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
        static Point moveTowards(Point p1, Point p2, double distance);
        void setX(double xrc);
        void yetX(double yrc);
        double getX() const;
        double getY() const;
    };

}

#endif