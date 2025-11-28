#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"
class Point {
private:
    const Fixed x;
    const Fixed y;
public:
    Point();
    Point(const float xValue, const float yValue);
    Point(const Point &copy);
    ~Point();

    Point &operator=(const Point &copy);

    Fixed getX() const;
    Fixed getY() const;
};

std::ostream& operator<<(std::ostream &out, const Point &point);
#endif