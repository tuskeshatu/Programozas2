#pragma once

#include "Partner.h"
#include <string>

class Person : public Partner
{
private:
    std::string firstName, lastName, taxNumber;

public:
    Person(std::string const &firstName, std::string const &lastName, std::string const &taxNumber, const long id)
        : Partner(id), firstName(firstName), lastName(lastName), taxNumber(taxNumber)
    {
    }
    ~Person() {}
    Person(const Person &other) : Partner(other), firstName(other.firstName), lastName(other.lastName), taxNumber(other.taxNumber)
    {
    }
    // Getter for names in Person
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
};