#include <iostream>
#include "serializable.h"

std::ostream &operator<<(std::ostream &os, const Serializable &s)
{
    s.serialize(os);
    return os;
}

std::istream &operator>>(std::istream &is, Serializable &s)
{
    s.deserialize(is);
    return is;
}
