#include "Partner.h"
#include "Company.h"
#include "Person.h"

#include <iostream>

void test(const Partner &Partner)
{
}

int main(int argc, char const *argv[])
{
    Person p("Menet", "Elek", "123", 456);
    Company c("Gigasoft", "789", 420);

    // Test Person getters
    std::string pFirstName = p.getFirstName();
    std::string pLastName = p.getLastName();
    long pId = p.getId();
    std::cout << pFirstName << " " << pLastName
              << "\tid: " << pId << std::endl;

    // Test Company getters
    std::string cName = c.getBusinessName();
    long cId = c.getId();
    std::cout << cName << "\tid: " << pId << std::endl;

    return 0;
}
