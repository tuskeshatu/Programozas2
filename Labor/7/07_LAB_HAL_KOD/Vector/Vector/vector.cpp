#include "vector.h"
// #define NDEBUG
#include <cassert>

Vector::Vector(unsigned maxElementsNum) : elementNum(0), maxElementsNum(maxElementsNum), pData(nullptr) {}

Vector::Vector(const Vector &theOther)
{
    pData = nullptr;
    *this = theOther;
}

Vector::~Vector()
{
    delete[] pData;
}

unsigned Vector::size() const
{
    return elementNum;
}

unsigned Vector::getMaxElementsNum() const
{
    return maxElementsNum;
}

void Vector::clear()
{
    delete[] pData;
    pData = NULL;
    elementNum = 0;
}

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

std::ostream &operator<<(std::ostream &os, const Vector &vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        os << vector[i] << " ";
    }

    return os;
}

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

int& Vector::operator[](unsigned idx)
{
    if (idx >= elementNum)
        throw std::out_of_range("Vector overindexed");
    
    return pData[idx];
}

const int& Vector::operator[](unsigned idx) const
{
    if (idx >= elementNum)
        throw std::out_of_range("Vector overindexed");
    
    return pData[idx];
}

void Vector::operator*=(unsigned param)
{
    for (unsigned i = 0; i < size(); i++)
        pData[i] *= param;
}