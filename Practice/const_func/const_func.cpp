#include <iostream>

class MyClass
{
public:
    void modifyMember()
    {
        myMember = 5; // Hiba: nem lehet módosítani egy nem konstans tagváltozót egy nem konstans tagfüggvényen belül
    }

    void printMember() const
    {
        std::cout << myMember << std::endl;
    }

private:
    int myMember = 0;
};

int main()
{
    /*const*/ MyClass obj;
    obj.modifyMember(); // Hiba: modifyMember() nem konstans tagfüggvény, így nem hívható meg egy konstans objektumon
    obj.printMember();
    return 0;
}