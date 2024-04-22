#include <string>
#include <ctime>
#include <random>

class Partner
{
private:
    char privateKey[2001];
    long id;

public:
    Partner(const long id) : id(id)
    {
        // Initialize private key as randoms
        for (int i = 0; i < 2001; i++)
        {
            srand(time(0));
            privateKey[i] = '0' + (rand() % 10);
        }
        
    }
    ~Partner();

    // Getter for id in Partner
    long getId() const { return id; }
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
        : Partner(id), firstName(firstName), lastName(lastName), taxNumber(taxNumber)
    {
    }
    ~Person();
    Person(const Person &other) : Partner(other), firstName(other.firstName), lastName(other.lastName), taxNumber(other.taxNumber)
    {
    }
    // Getter for names in Person
    std::string getFirstName() const { return firstName; }
    std::string getLastName() const { return lastName; }
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

    // Getter for businessName in Company
    std::string getBusinessName() const { return businessName; }
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
