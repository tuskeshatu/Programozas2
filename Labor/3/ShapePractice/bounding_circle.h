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
	BoundingCircle(double square_side = 1);

	void print() const;

	Rectangle getInnerSquare() const { return innerSquare; };
	circle getOuterCircle() const { return outerCircle; };

	double getArea() const { return outerCircle.getArea() - innerSquare.getArea(); };
	double getPerimeter() const { return outerCircle.getCircum() + innerSquare.getPerimeter(); };
};

#endif // BOUNDINGCIRCLE_HPP
