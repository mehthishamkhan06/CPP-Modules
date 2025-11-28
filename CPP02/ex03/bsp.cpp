#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed areaABC = (b.getX() - a.getX()) * (c.getY() - a.getY()) - (c.getX() - a.getX()) * (b.getY() - a.getY());
    Fixed areaPAB = (b.getX() - point.getX()) * (a.getY() - point.getY()) - (a.getX() - point.getX()) * (b.getY() - point.getY());
    Fixed areaPBC = (c.getX() - point.getX()) * (b.getY() - point.getY()) - (b.getX() - point.getX()) * (c.getY() - point.getY());
    Fixed areaPCA = (a.getX() - point.getX()) * (c.getY() - point.getY()) - (c.getX() - point.getX()) * (a.getY() - point.getY());

    bool has_neg = (areaPAB < Fixed(0)) || (areaPBC < Fixed(0)) || (areaPCA < Fixed(0));
    bool has_pos = (areaPAB > Fixed(0)) || (areaPBC > Fixed(0)) || (areaPCA > Fixed(0));

    return !(has_neg && has_pos);
}