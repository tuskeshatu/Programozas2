#include "bounding_circle.h"
#include <cmath>

BoundingCircle::BoundingCircle(double square_side)
{
    innerSquare = Rectangle (square_side, square_side);
    outerCircle = circle (square_side * sqrt(2) / 2);
}

void BoundingCircle::print() const
{
    innerSquare.print();
    outerCircle.print();
}