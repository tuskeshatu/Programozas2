#pragma once

#include "Partner.h"
#include <string>

class Company : public Partner
{
private:
    std::string businessName, vatId;

public:
    Company(const std::string &businessName, const std::string &vatId, const long id)
        : Partner(id), businessName(businessName), vatId(vatId)
    {
    }
    ~Company() {}

    // Getter for businessName in Company
    std::string getBusinessName() const { return businessName; }
};