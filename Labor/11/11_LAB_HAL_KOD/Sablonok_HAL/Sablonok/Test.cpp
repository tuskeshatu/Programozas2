#include <iostream>




// 1.c Eg�sz�tsd ki a Vector2D oszt�lyt a find_max_elem feladathoz
class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    double length() const {
	//Fixme!
        return 0;
    }
};

//1.a feladat tesztel�se
void swapTest() {
    int x = 5, y = 10;
    std::cout << "Eredeti �rt�kek: x = " << x << ", y = " << y << std::endl;
    //1. val�s�tsd meg a swap f�ggv�nysablont.
    //swap(x, y);
    std::cout << "Csere ut�n: x = " << x << ", y = " << y << std::endl;

    double c = 3.14, d = 2.71;
    //2. h�vd meg a swap f�ggv�nyt double t�pus� v�ltoz�kra is.

}


// 1.b feladat tesztel�se - kommentezd ki �s h�vd meg, ha megval�s�tottad a find_max_elem sablont. A lenti k�dot ne �rd �t!
/*
void maxTest() {
    int intArray[] = { 1, 3, 5, 2, 4 };
    double doubleArray[] = { 1.5, 3.2, 2.7, 4.1 };
    int* emptyArray= nullptr;

    int* maxInt = find_max_elem(intArray, 5);
    double* maxDouble = find_max_elem(doubleArray, 4);

    if (maxInt)
        std::cout << "Maximum integer: " << *maxInt << std::endl;
    else
        std::cout << "Empty integer array." << std::endl;

    if (maxDouble)
        std::cout << "Maximum double: " << *maxDouble << std::endl;
    else
        std::cout << "Empty double array." << std::endl;

    maxInt = find_max_elem(emptyArray, 0);
    if (maxInt)
        std::cout << "Maximum integer: " << *maxInt << std::endl;
    else
        std::cout << "Empty integer array." << std::endl;

    ////////////////////////////////////
    1.c feladat - kommentezd ki, ha a Vector2D oszt�lyt megval�s�tottad.

    //Vector2D vectors[] = { Vector2D(1.0, 2.0), Vector2D(3.0, 4.0), Vector2D(0.5, 0.5) };
    //Vector2D* maxVector = find_max_elem(vectors, 3);

    //if (maxVector)
    //    std::cout << "Maximum vector length: " << maxVector->length() << std::endl;
    //else
    //    std::cout << "Empty vector array." << std::endl;


}

*/


int main() {

    swapTest();
    //maxTest();

    return 0;
}


