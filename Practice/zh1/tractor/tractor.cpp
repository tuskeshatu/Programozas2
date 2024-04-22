#include <iostream>
#include <algorithm>
#include <stdexcept>

class Spray
{
private:
    unsigned type;
    bool used;

public:
    Spray(unsigned type = 0) : type(type), used(false) {}
    ~Spray() {}

    void vaporize()
    {
        if (used)
        {
            std::cout << "Mar felhasznaltak." << std::endl;
            return;
        }

        used = true;
        std::cout << "Permet: " << type << std::endl;
    }
};

class Tractor
{
private:
    Spray *sprays;
    unsigned spraysCount;

public:
    Tractor() : sprays(nullptr), spraysCount(0) {}
    ~Tractor()
    {
        delete[] sprays;
    }

    void addSpray(Spray& paramSpray)
    {
        Spray *newSpray = new Spray[spraysCount + 1];

        std::copy(sprays, sprays + spraysCount, newSpray);
        
        newSpray[spraysCount] = paramSpray;
        spraysCount++;

        delete[] sprays;
        sprays = newSpray;
    }

    Spray& operator[](unsigned idx) const
    {
        if (idx >= spraysCount)
        {
            throw std::out_of_range("Sprays overindexed!");
        }
        
        return sprays[idx];
    }
};

int main() { 
  Tractor zetor; 
  Spray s1(1); //1-es tipus, pl. csigaolo permet 
  Spray s2(2); //2-es tipus, pl. bekataszito permet 
  zetor.addSpray(s1); 
  zetor.addSpray(s2); 
  zetor[0].vaporize(); //(*) “Permet: 1” 
  //A túlcímzéssel nem kell foglalkoznunk. 
  zetor[0].vaporize(); // “Mar felhasznaltak.” 
  zetor[1].vaporize(); //”Permet: 2” 
}