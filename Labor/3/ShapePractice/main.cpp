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

    printf("\nTesting BoundingCircle...\n");
    BoundingCircle b1;
    BoundingCircle b2(10);
    b1.print();                                           // inner square: a=1.00, b=1.00\nouter circle: r=0.71
    b2.print();                                           // inner square: a=10.00, b=10.00\nouter circle: r=7.07
    printf("Area of c1=%.2lf\n", b1.getArea());           // Area of c1=0.57
    printf("Area of c2=%.2lf\n", b2.getArea());           // Area of c2=57.08
    printf("Perimeter of c1=%.2lf\n", b1.getPerimeter()); // Perimeter of c1=8.44
    printf("Perimeter of c2=%.2lf\n", b2.getPerimeter()); // Perimeter of c2=84.43
    b1.getInnerSquare().print();                          // a=1.00, b=1.00
    b1.getOuterCircle().print();                          // r=0.71

    return 0;
}
