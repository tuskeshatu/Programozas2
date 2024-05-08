#include <cstddef>
#include <stdexcept>

#include "sharedPointer.h"

// valuePtr pointing to the value needing to be stored
// countPtr pointing to the number of pointers pointing to this value
SharedPointer::SharedPointer(double *const valuePtr) : valuePtr(valuePtr), countPtr(nullptr)
{
    // If value is given to initialize, countPtr is 1 (1 is already pointing to this)
    if (valuePtr != nullptr)
        countPtr = new size_t(1);
}

// Destructor handles deletion if it is the last pointing to it
SharedPointer::~SharedPointer()
{
    // Decrease count if not nullptr
    if (countPtr != nullptr)
        (*countPtr)--;

    // If count is zero, delete everything and set them to nullptr
    if (countPtr != nullptr && *countPtr == 0)
    {
        delete countPtr;
        countPtr = nullptr;

        delete valuePtr;
        valuePtr = nullptr;
    }
    else
    {
        // Set the currently deleted pointer to nullptr
        valuePtr = nullptr;
        countPtr = nullptr;
    }
}

// Copy constructor
SharedPointer::SharedPointer(const SharedPointer &other)
{
    // Copy values and increment count
    valuePtr = other.valuePtr;
    countPtr = other.countPtr;
    if (countPtr != nullptr)
        (*countPtr)++;
}

// Operator =
SharedPointer &SharedPointer::operator=(const SharedPointer &other)
{
    // Make sure they are not the same
    if (this == &other)
        return *this;

    // Decrease count of this, because this will now be pointing at something different
    if (countPtr != nullptr)
        (*countPtr)--;
    // Clean up after this is this is the last one pointing to the value
    if (countPtr != nullptr && *countPtr == 0)
    {
        delete countPtr;
        delete valuePtr;
    }

    // Set this to the other
    valuePtr = other.valuePtr;
    countPtr = other.countPtr;

    // Increment count, because this is now pointing to the other value
    (*countPtr)++;
    // Return for chainability
    return *this;
}

// Dereference operator
// Throws runtime error if nullptr
double SharedPointer::operator*() const
{
    // Check if valuePtr is valid
    if (valuePtr == nullptr)
        throw std::runtime_error("SharedPointer: Dereferencing nullptr (SharedPointer)");

    // Return value
    return *valuePtr;
}

// Compare SharedPointer with other SharedPointer
// Only returns true if both are pointing to the same address
bool SharedPointer::operator==(const SharedPointer &other) const
{
    return valuePtr == other.valuePtr;
}

// Compare double * to SharedPointer
// Be careful, when pointing a normal pointer
// to a value used by a SharedPointer to prevent double delete
bool SharedPointer::operator==(const double *const doublePtr) const
{
    return doublePtr == valuePtr;
}