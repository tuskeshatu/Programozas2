#include "vector.h"
// #define NDEBUG
#include <cassert>

// Constructor
Vector::Vector(unsigned maxElementsNum) : elementNum(0), maxElementsNum(maxElementsNum), pData(nullptr) {}

// Copy constructor
Vector::Vector(const Vector &theOther)
{
    pData = nullptr;
    *this = theOther;
}

// Destructor
Vector::~Vector()
{
    delete[] pData;
}

// Get the number of elements in the vector
unsigned Vector::size() const
{
    return elementNum;
}

// Get a constant reference to the element at the specified index
const int &Vector::at(unsigned idx) const
{
    return (*this)[idx];
}

// Get a reference to the element at the specified index
int &Vector::at(unsigned idx)
{
    return (*this)[idx];
}

// Get the maximum number of elements the vector can hold
unsigned Vector::getMaxElementsNum() const
{
    return maxElementsNum;
}

// Clear the vector (delete all elements)
void Vector::clear()
{
    delete[] pData;
    pData = NULL;
    elementNum = 0;
}

// Erase an element at the specified position
bool Vector::erase(unsigned position)
{
    if (position >= elementNum)
    {
        std::cerr << "Hibas index";
        return false;
    }

    if (elementNum == 1)
    {
        delete[] pData;
        pData = NULL;
        elementNum = 0;
        return true;
    }

    int *pTemp = new int[--elementNum];
    for (unsigned i = 0, j = 0; i < elementNum + 1; i++, j++)
    {
        if (i == position)
            j--;
        else
            pTemp[j] = pData[i];
    }
    delete[] pData;
    pData = pTemp;
    return true;
}

// Insert an element at the specified position
bool Vector::insert(unsigned position, int element)
{
    if (elementNum == maxElementsNum)
    {
        std::cerr << "Tobb elem nem fer el a tombben!" << std::endl;
        return false;
    }

    int *pTemp = nullptr;
    if (position < elementNum)
    {
        pTemp = new int[elementNum + 1];

        for (unsigned i = 0, j = 0; i < elementNum; i++, j++)
        {
            if (j == position)
            {
                pTemp[position] = element;
                i--;
            }
            else
                pTemp[j] = pData[i];
        }
        elementNum++;
    }
    else
    {
        pTemp = new int[position + 1];
        for (unsigned i = 0; i < position; i++)
        {
            if (i < elementNum)
                pTemp[i] = pData[i];
            else
                pTemp[i] = 0;
        }
        pTemp[position] = element;
        elementNum = position + 1;
    }
    delete[] pData;
    pData = pTemp;
    return true;
}

// Overload the << operator for outputting the vector
std::ostream &operator<<(std::ostream &os, const Vector &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        // For efficiency (no unnecessary function calls) friend. 
        // It can index into pData directly, no need for operator[] call.
        //os << vector[i] << " ";

        os << vector.pData[i] << " ";

        if (!os.good())
            throw std::runtime_error("Failed to write to output stream");
    }

    return os;
}

// Overload the >> operator for inputting the vector
std::istream &operator>>(std::istream &is, Vector &vector)
{
    for (unsigned i = 0; i < vector.getMaxElementsNum(); i++)
    {
        int element;
        is >> element;

        if (is.good())
            vector.insert(i, element);
        else
            throw std::invalid_argument("Failed to read element from input stream");
    }

    return is;
}

// Assignment operator
Vector &Vector::operator=(const Vector &rhs)
{
    if (this == &rhs)
        return *this;

    delete[] pData;

    pData = new int[rhs.size()];

    elementNum = rhs.elementNum;

    for (size_t i = 0; i < rhs.size(); i++)
    {
        pData[i] = rhs.pData[i];
    }

    return *this;
}

// Overload the [] operator for accessing elements by index
int &Vector::operator[](unsigned idx)
{
    if (idx >= elementNum)
        throw std::out_of_range("Vector overindexed");

    return pData[idx];
}

// Overload the [] operator for accessing elements by index (const version)
const int &Vector::operator[](unsigned idx) const
{
    if (idx >= elementNum)
        throw std::out_of_range("Vector overindexed");

    return pData[idx];
}

// Multiply all elements of the vector by a parameter
void Vector::operator*=(unsigned param)
{
    for (unsigned i = 0; i < size(); i++)
        pData[i] *= param;
}

// Add a parameter to all elements of the vector
void Vector::operator+=(unsigned param)
{
    for (unsigned i = 0; i < size(); i++)
        pData[i] += param;
}

// Sorters and sort implementation

// Sorting functions for ascending
bool Sorters::ascend(const int &a, const int &b)
{
    return a > b;
}

// Sorting functions for descending
bool Sorters::descend(const int &a, const int &b)
{
    return a < b;
}

// Sort the vector using function pointer param
void Vector::sort(bool (*compare)(const int &, const int &))
{
    for (unsigned i = 1; i < size(); i++)
    {
        int key = pData[i];
        int j = i - 1;

        // Move element if needed to the right
        while (j >= 0 && compare(pData[j], key))
        {
            pData[j + 1] = pData[j];
            j--;
        }

        // Insert key marker at the correct position
        pData[j + 1] = key;
    }
}