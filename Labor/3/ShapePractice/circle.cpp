#include "circle.h"
#include <cstdio>

circle::circle(double r)
{
    this->r = r;
}

void circle::setr(double newr = 0)
{
    r = newr;
}

void circle::print() const
{
    printf("circle: r = %f, area = %f, circum = %f\n", r, getArea(), getCircum());
}