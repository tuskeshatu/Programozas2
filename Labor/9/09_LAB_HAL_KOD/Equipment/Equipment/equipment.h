#pragma once

#include <string>
#include <iostream>

class Equipment
{
private:
    int serial_number;

public:
    Equipment(int sn = -1) : serial_number(sn) {}
    virtual ~Equipment() {}

    virtual void print(std::ostream &os) const
    {
        os << "Equipment; serial number: " << serial_number;
    }
};

std::ostream &operator<<(std::ostream& os, const Equipment &e);