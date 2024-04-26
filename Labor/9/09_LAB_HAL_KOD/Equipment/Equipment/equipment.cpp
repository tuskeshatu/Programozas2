#include "equipment.h"

std::ostream &operator<<(std::ostream& os, const Equipment &e)
{
    e.print(os);
    return os;
}