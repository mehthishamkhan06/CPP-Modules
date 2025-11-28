#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0)) {}

Point::Point(const float xValue, const float yValue) : x(Fixed(xValue)), y(Fixed(yValue)) {}

Point::Point(const Point &copy) : x(copy.x), y(copy.y) {}

Point::~Point() {}

Point &Point::operator=(const Point &copy) {
    (void)copy; // Assignment operator does nothing since x and y are const
    return *this;
}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}

std::ostream& operator<<(std::ostream &out, const Point &point) {
    out << "(" << point.getX() << ", " << point.getY() << ")";
    return out;
}

