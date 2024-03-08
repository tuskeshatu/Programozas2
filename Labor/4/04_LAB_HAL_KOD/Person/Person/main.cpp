#include <iostream>
#include "person.h"

int main(int argv, char*argc[]) {
	Person* p1 = new Person();
	Person p2("Aladar", 13);
	Person p3(p2);

	p1->setName("Bela");
	(*p1).setAge(15); // a->b === (*a).b

	// while(pontok--);, ha new ut�n nincs delete!
	delete p1;

	return 0;
}