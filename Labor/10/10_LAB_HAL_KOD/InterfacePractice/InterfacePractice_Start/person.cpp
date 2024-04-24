#include "person.h"

using namespace std;

Person::Person(unsigned char age, double height, double weight) : age(age), height(height), weight(weight) {}

void Person::setAge(unsigned char age)
{
	this->age = age;
}

int Person::getAge() const
{
	return age;
}

bool Person::setHeight(double height)
{
	if (height<10 || height>300)
		return false;
	this->height = height;
	return true;
}

double Person::getHeight() const
{
	return height;
}


bool Person::setWeight(double weight)
{
	if (weight<0 || weight>400)
		return false;

	this->weight = weight;

	return true;
}

double Person::getWeight() const
{
	return weight;
}


void Person::serialize(ostream& os) const
{
	// unsigned char -> int, különben karakterként írja ki
	os << (int)age << '\t' << height << '\t' << weight << endl;
}

void Person::deserialize(istream& is)
{
	double height;
	double weight;
	int age;
	char c;

	is >> age;
	is >> c;
	if (c != ';')
		is.clear(ios::failbit);

	is >> height;
	is >> c;
	if (c != ';')
		is.clear(ios::failbit);

	is >> weight;

	if (is)
	{
		this->age = age;
		this->height = height;
		this->weight = weight;
	}
	else
		cerr << "Error in input format." << endl;
}

ostream& operator<<(ostream& os, const Person& right)
{
	//TODO
	return os;
}
