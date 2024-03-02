#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class circle
{
private:
	double r;

public:
	circle(double r = 0);
	~circle(){};

	void setr(double);

	double getr() const { return r; };

	double getArea() const { return r * r * 3.14; };
	double getCircum() const { return 2 * r * 3.14; };

	void print() const;
};

#endif // CIRCLE_HPP
