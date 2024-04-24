#pragma once

#include <ctime>
#include <random>

class Partner
{
private:
    char privateKey[2001];
    const long id;

public:
    Partner(const long id) : id(id)
    {
        // Set seed for rand()
        srand(time(NULL));
        // Initialize private key as randoms
        for (int i = 0; i < 2001; i++)
            privateKey[i] = '0' + (rand() % 10);
    }
    ~Partner() {}

    // Getter for id in Partner
    long getId() const { return id; }
};