#include <cstdio>
#include "rectangle.h"
#include "circle.h"
#include "bounding_circle.h"

int main(int argc, char const *argv[])
{
    Rectangle r1;

    Rectangle r2(2, 7);

    r2.seta(5.3);
    r2.setb(r2.getb() * 3);

    double a = r2.getArea();

    double c = r2.getPerimeter();

    r1.print();
    r2.print();

    circle c1;

    circle c2(6);

    c2.setr(c2.getr() / 2);

    c1.print();
    c2.print();

    BoundingCircle bc(4);

    double bca = bc.getArea();

    return 0;
}
