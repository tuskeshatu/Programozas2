#pragma once
#include <cstddef>
#include <iostream>

class SharedPointer
{
private:
    // valuePtr:    Pointer to the value stored by SharedPointer
    // countPtr:    Pointer to number of SharedPointers pointing to the same address (value)
    double *valuePtr;
    size_t *countPtr;

public:
    // Constructor with default value of nullptr
    SharedPointer(double *const valuePtr = nullptr);
    // Destructor managing deletion of pointers
    ~SharedPointer();
    // Copy constructor
    SharedPointer(const SharedPointer &);
    // getCount:    Get *countPtr
    size_t getCount() const
    {
        if (countPtr != nullptr)
            return *countPtr;
        return 0;
    }
    // Assignment operator
    SharedPointer &operator=(const SharedPointer &other);
    // Dereference operator
    double operator*() const;
    // Compare operator for other SharedPointer
    bool operator==(const SharedPointer &other) const;
    // Compare operator for double pointers
    bool operator==(const double *const) const;
};