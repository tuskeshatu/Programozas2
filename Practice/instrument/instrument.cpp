#include <cstring>
#include <iostream>

class Instrument
{
public:
    char *unique_id;

    Instrument(const char *param)
    {
        unique_id = new char[strlen(param) + 1];
        strcpy_s(unique_id, strlen(param) + 1, param);
    }
};

void Play(Instrument i)
{
    std::cout << "Playing the " << i.unique_id << std::endl;
}

int main(int argc, char const *argv[])
{
    Instrument piano1 = "Piano_123";
    Play(piano1);

    return 0;
}
