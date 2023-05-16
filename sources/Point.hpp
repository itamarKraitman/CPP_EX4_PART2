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
        static Point moveTowards(Point po1, Point po2, double distance);
        void setX(double xcr);
        void setY(double ycr);
        double getX() const;
        double getY() const;
    };

}

#endif