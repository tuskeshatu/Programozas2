#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle
{
private:
	double a, b;

public:
	Rectangle(double a = 0, double b = 0);
	~Rectangle(){};

	void seta(double);
	void setb(double);

	double geta() const { return a; };
	double getb() const { return b; };

	double getArea() const { return a * b; };
	double getPerimeter() const { return 2 * (a + b); };

	void print() const;
};

#endif // RECTANGLE_HPP
