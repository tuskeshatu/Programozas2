#pragma once

#include "comparable.h"

class Dog : public Comparable
{
private:
    /* data */
public:
    bool operator==(const Comparable &other) const override
    {
        return false;
    }

    bool operator<(const Comparable &other) const override
    {
        return true;
    }
};
