#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);
int main() {
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(2.5f, 5.0f);

    Point insidePoint(2.5f, 2.0f);
    Point outsidePoint(5.0f, 5.0f);
    Point edgePoint(2.5f, 0.0f);

    std::cout << "Triangle vertices: A" << a << ", B" << b << ", C" << c << std::endl;

    std::cout << "Testing point " << insidePoint << ": ";
    if (bsp(a, b, c, insidePoint))
        std::cout << "Inside the triangle." << std::endl;
    else
        std::cout << "Outside the triangle." << std::endl;

    std::cout << "Testing point " << outsidePoint << ": ";
    if (bsp(a, b, c, outsidePoint))
        std::cout << "Inside the triangle." << std::endl;
    else
        std::cout << "Outside the triangle." << std::endl;

    std::cout << "Testing point " << edgePoint << ": ";
    if (bsp(a, b, c, edgePoint))
        std::cout << "Inside the triangle." << std::endl;
    else
        std::cout << "Outside the triangle." << std::endl;

    return 0;
}