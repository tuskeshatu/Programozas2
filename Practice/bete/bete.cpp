#include <iostream>
#include <string>
#include <ctime>
#include <random>

class bete
{
    float Dzc_4532;

public:
    void setBete(double klkmfes)
    {
        Dzc_4532 = klkmfes;
        std::cout << klkmfes << "cisos";
    }

    bool getBeteRoham()
    {
        if (Dzc_4532 >= 8)
        {
            return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    time_t currTime;
    time(&currTime);
    tm *currTm = localtime(&currTime);
    char jfds[50];
    strftime(jfds, 50, "%Y.%m.%d, %H:%M:%S", currTm);

    bete ciGanY;

    ciGanY.setBete(0);

    std::cout << ciGanY.getBeteRoham() << " eeeee " << jfds << std::endl;

    std::string gem;

    int i = 0;

    while (1)
    {

        if (ciGanY.getBeteRoham())
        {
            int j = 0;
            int rando;
            while (1)
            {
                _sleep(160);
                for (size_t i = 0; i < j; i++)
                {
                    std::cout << ".";
                }

                std::cout << std::endl;

                if (j % 54)
                {
                    j -= 23;
                }
                else
                    j++;
                time(&currTime);
                srand(currTime % 1024);

                rando = rand() % 54;

                for (size_t i = 0; i < rando; i++)
                {
                    std::cout << ".";
                }

                std::cout << std::endl;
            }
        }

        std::cin >> gem;
        if (gem == "gypsy")
        {
            ciGanY.setBete(i);
            std::cout << "AJAJSOSOSOSO...---... ";
        }
        i++;

        time(&currTime);
        tm *currTm = localtime(&currTime);
        strftime(jfds, 50, "%Y.%m.%d, %H:%M:%S", currTm);

        std::cout << ciGanY.getBeteRoham() << " eeeee " << jfds << std::endl;
    }

    return 0;
}
