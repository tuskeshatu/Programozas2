#include <fstream>
#include "person.h"
#include "comparable.h"
#include "serializable.h"
#include "saver.h"
#include "dog.h"

using namespace std;

void mySort(Comparable **p, size_t n)
{
	if (*p[0] < *p[1])
	{
	}
}

int main()
{
	const unsigned PEOPLE_COUNT = 4;

	// Vele fogunk összehasonlítani az 1.b-ben
	Person *pisti = new Person(30, 180, 85);
	Person *people[PEOPLE_COUNT];

	people[0] = new Person(40, 182, 90);
	people[1] = new Person(12, 100, 50);
	people[2] = new Person(30, 180, 85);
	people[3] = new Person(40, 182, 90);

	{
		std::ofstream ofs("people.txt");
		for (size_t i = 0; i < PEOPLE_COUNT; i++)
		{
			ofs << *people[i] << endl;
		}
	} // Block to make ofs go out of scope and call it's destructor:
	  // RAII

	ifstream ifs("people.txt");
	Person p(0, 0, 0);
	while (ifs >> p)
	{
		std::cout << p;
	}
	ifs.close(); // This is the other way to close fstream

	Dog d;

	// if (*pisti < d)
	// {
	// 	cout << *pisti << " kisebb mint";
	// }

	cout << endl << pisti << "\t" << (Serializable *) pisti
	<< "\t" << (Comparable *) pisti;

	mySort((Comparable **)people, 4);

#if 0
	//1.a feladat tesztelése
	cout << "\tSerializing people" << endl;
	cout << "State\tIndex\tAge\tHeight\tWeight" << endl;
	for (unsigned i = 0; i < PEOPLE_COUNT; i++)
	{
		cout << "Ser.\t" << i << '\t' << *people[i] << endl;
	}

	//1.b feladat tesztelése
	//cout << "\tComparing people in array with 'pisti'" << endl;
	//cout << "State\tIndex\tAge\tHeight\tWeight" << endl;
	//for (unsigned i = 0; i < PEOPLE_COUNT; i++)
	//{
	//	cout << "------------------------------------" << endl; 
	//	cout << "Comp.\t" << i << '\t' << *people[i] << endl;
	//	cout << "Has the same age as Pisti? "  << (*people[i] == *pisti) << endl;
	//	cout << "Is younger than Pisti? " << (*people[i] < *pisti) << endl;
	//}

	//2.a feladat: írd ki a people tömb elemeit a "people.txt" fájlba
	//
	//
	//
	//
#endif
	delete pisti;
	for (unsigned k = 0; k < PEOPLE_COUNT; k++)
		delete people[k];

	return 0;
}