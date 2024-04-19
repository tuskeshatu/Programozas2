#include <string>

class Partner
{
private:
    char *privateKey[2001];
    long id;

public:
    Partner(const long id) : id(id)
    {
        // initialize private key as randoms
    }
    ~Partner();
};

Partner::~Partner()
{
}

class Person : public Partner
{
private:
    std::string firstName, lastName, taxNumber;

public:
    Person(std::string const &firstName, std::string const &lastName, std::string const &taxNumber, const long id)
        : Partner(id)
        , firstName(firstName)
        , lastName(lastName)
        , taxNumber(taxNumber)
    {

    } 
    ~Person();
    Person(const Person &other):
    Partner(other), firstName(other.firstName), lastName(other.lastName), taxNumber(other.taxNumber)
    {

    }
};

Person::~Person()
{
}

class Company : public Partner
{
private:
    std::string businessName, vatId;

public:
    Company(const std::string &businessName, const std::string &vatId, const long id)
    : Partner(id), businessName(businessName), vatId(vatId)
    {

    }
    ~Company();
};

Company::~Company()
{
}


void test(const Partner &Partner)
{

}

int main(int argc, char const *argv[])
{
    Person p("Misi", "Pisi", "69420", 1234);
    test(p);
    return 0;
}
