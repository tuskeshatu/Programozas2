#include "Vector.h"

#include <iostream>

using namespace std;

class Point
{
private:
	double x;
	double y;

public:
	Point(double x_val = 0, double y_val = 0) : x(x_val), y(y_val) {}

	friend std::ostream &operator<<(std::ostream &os, const Point &point);
};

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "x: " << point.x << "\ty: " << point.y;
	return os;
}

void vectorTest()
{
	Vector<Point> v1;

	// Insert tesztelése
	for (int i = 1; i < 10; i++)
		v1.insert(i, Point(i, i + 1));

	// A kiírás (operator<<) és az at() függvény tesztelése
	cout << v1 << endl;
	// Elvárt kimenet: 0 1 2 3 4 5 6 7 8 9

	// Másoló konstruktor
	Vector<Point> v2(v1); // Lehetne: Vector v2=v1;

	// operator=
	Vector<Point> v3;
	v3 = v2;

	// Megváltoztatjuk v1-t (erase tesztelése)
	v1.erase(0);

	// v1.erase(9); // false

	cout << endl
		 << v1 << endl
		 << v2 << endl
		 << v3 << endl;
	// Elvárt kimenet:
	// 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9
	// 0 1 2 3 4 5 6 7 8 9

	v2.insert(0, Point(-1, -1));
	cout << endl
		 << v2 << endl;
	// Elvárt kimenet: -1 0 1 2 3 4 5 6 7 8 9

	v2.insert(10, Point(-1, -1));
	cout << endl
		 << v2 << endl;
	// Elvárt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9

	v2.insert(12, Point(-1, -1));
	cout << endl
		 << v2 << endl;
	// Elvárt kiment: -1 0 1 2 3 4 5 6 7 8 -1 9 -1

	v2.insert(15, Point(-1, -1));
	cout << endl
		 << v2 << endl;
	// Elvárt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -1

	//v2[15] = Point(-2, -2);
	cout << endl
		 << v2 << endl;
	// Elvárt kimenet: -1 0 1 2 3 4 5 6 7 8 -1 9 -1 0 0 -2
}
