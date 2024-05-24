#include <iostream>
#include <cmath>
#include <vector>
#include <list>

bool negativeInt(int a) { return a < 0; }
bool negativeDouble(int a) { return a < 0; }

template <class T>
bool isNegative(T a) { return a < 0; }

template <class T>
struct less_than
{
    T a;
    less_than(const T &a) : a(a) {}
    bool operator()(const T &x) const { return x < a; }
};

template <class T>
struct less
{
    bool operator()(const T &a, const T &b) const { return a < b; }
};

template <class T, class P>
size_t countIf(T first, T last, P pred)
{
    size_t count = 0;

    for (; first != last; first++)
    {
        if (pred(*first))
            count++;
    }

    return count;
}

template <class T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class function, class T>
struct bound2nd
{
    function f;
    T v;
    bound2nd(function f, T v) : f(f), v(v) {}
    bool operator()(const T &x) const { return f(v, x); }
};

template <class function, class T>
bound2nd<function, T> bind2nd(function f, const T &v)
{
    return bound2nd<function, T>(f, v);
}

#if 0

int main()
{

    int a = 1, b = 2;
    swap(a, b);

    double c = 3.14, d = 6.9;
    swap(c, d);

    int intarr[]{1, 2, -3, 2};
    size_t testcnt = countIf(intarr, intarr + 4, isNegative<int>);

    double doublearr[]{-3.6, 4.2, -9.6, 2.1};
    testcnt = countIf(doublearr, doublearr + 4, isNegative<double>);

    testcnt = countIf(intarr, intarr + 4, less_than<int>(2));
    testcnt = countIf(doublearr, doublearr + 4, less_than<double>(3));

    std::vector<double> doubleVector;
    doubleVector.push_back(6.9);
    doubleVector.push_back(3.14);
    doubleVector.push_back(4.20);
    testcnt = countIf(doubleVector.begin(), doubleVector.end(), less_than<double>(5));

    std::list<double> doubleList;
    doubleList.push_back(6.9);
    doubleList.push_back(3.14);
    doubleList.push_back(4.20);
    testcnt = countIf(doubleList.begin(), doubleList.end(), less_than<double>(5));


    testcnt = countIf(doubleList.begin(), doubleList.end(), bind2nd(less<double>(), 5));
    return 0;
}

#endif

// 1.c Eg�sz�tsd ki a Vector2D oszt�lyt a find_max_elem feladathoz
class Vector2D
{
private:
    double x;
    double y;

public:
    Vector2D(double x_val, double y_val) : x(x_val), y(y_val) {}

    double length() const
    {
        return std::sqrt(x * x + y * y);
    }

    bool operator>(const Vector2D &other)
    {
        return length() > other.length();
    }

    bool operator<(const Vector2D &other)
    {
        return length() > other.length();
    }
};

// 1.a feladat tesztel�se
void swapTest()
{
    int x = 5, y = 10;
    std::cout << "Eredeti ertekek: x = " << x << ", y = " << y << std::endl;
    // 1. val�s�tsd meg a swap f�ggv�nysablont.
    swap(x, y);
    std::cout << "Csere utan: x = " << x << ", y = " << y << std::endl;

    double c = 3.14, d = 2.71;
    // 2. h�vd meg a swap f�ggv�nyt double t�pus� v�ltoz�kra is.
    std::cout << "Eredeti ertekek: c = " << x << ", d = " << y << std::endl;
    // 1. val�s�tsd meg a swap f�ggv�nysablont.
    swap(x, y);
    std::cout << "Csere utan: c = " << x << ", d = " << y << std::endl;
}

// 1.b feladat tesztel�se - kommentezd ki �s h�vd meg, ha megval�s�tottad a find_max_elem sablont. A lenti k�dot ne �rd �t!

template <class T>
T *find_max_elem(T arr[], size_t size)
{
    T *maxElem = nullptr;
    if (size > 0)
    {
        maxElem = &arr[0];
        for (size_t i = 1; i < size; i++)
        {
            if (arr[i] > *maxElem)
            {
                maxElem = &arr[i];
            }
        }
    }
    return maxElem;
}

void maxTest()
{
    int intArray[] = {1, 3, 5, 2, 4};
    double doubleArray[] = {1.5, 3.2, 2.7, 4.1};
    int *emptyArray = nullptr;

    int *maxInt = find_max_elem(intArray, 5);
    double *maxDouble = find_max_elem(doubleArray, 4);

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
    // 1.c feladat - kommentezd ki, ha a Vector2D osztalyt megvalositottad.

    Vector2D vectors[] = {Vector2D(1.0, 2.0), Vector2D(3.0, 4.0), Vector2D(0.5, 0.5)};
    Vector2D *maxVector = find_max_elem(vectors, 3);

    if (maxVector)
        std::cout << "Maximum vector length: " << maxVector->length() << std::endl;
    else
        std::cout << "Empty vector array." << std::endl;
}

int main()
{

    swapTest();
    maxTest();

    return 0;
}
