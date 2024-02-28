#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle
{
private:
	double a, b;
	void seta(double);
	void setb(double);

public:
	Rectangle();
	~Rectangle();

	double geta() { return a; };
	double getb() { return b; };
};

#endif // RECTANGLE_HPP
