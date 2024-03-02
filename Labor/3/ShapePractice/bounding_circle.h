#ifndef BOUNDINGCIRCLE_HPP
#define BOUNDINGCIRCLE_HPP

#include "rectangle.h"
#include "circle.h"

class BoundingCircle
{
private:
	Rectangle innerSquare;
	circle outerCircle;

public:
	BoundingCircle(double a = 0);
};

#endif // BOUNDINGCIRCLE_HPP
