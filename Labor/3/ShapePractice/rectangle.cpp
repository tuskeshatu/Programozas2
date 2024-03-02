#include "rectangle.h"
#include <cstdio>

Rectangle::Rectangle(double a, double b)
{
    this->a = a;

    this->b = b;
}

void Rectangle::seta(double param)
{
    a = param;
}
void Rectangle::setb(double param)
{
    b = param;
}

void Rectangle::print() const
{
    printf("Rectangle a: %f b:%f area: %f circum:%f\n", a, b, getArea(), getPerimeter());
}