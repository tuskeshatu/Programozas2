#include <iostream>

class Car
{
private:
    const unsigned number;
    int order;
    static unsigned currOrder;

public:
    Car(unsigned number) : number(number), order(-1) {}
    ~Car(){};

    void entersTrack()
    {
        order = currOrder;
        currOrder++;
    }

    unsigned getNumber() const
    {
        return number;
    }

    int getOrder() const
    {
        return order;
    }

    bool operator<(const Car &theOther) const
    {
        return order < theOther.order;
    }

    bool operator>(const Car &theOther) const
    {
        return order > theOther.order;
    }

    bool isEntered() const
    {
        return (getOrder() != -1);
    }
};

std::ostream &operator<<(std::ostream &os, Car &car)
{
    if (!car.isEntered())
    {
        os << "Car " << car.getNumber() << " has not entered the track yet.";
        return os;
    }

    os << "Car " << car.getNumber() << " entered the track as the "
       << car.getOrder() << ". car";
    return os;
}

unsigned Car::currOrder = 1;

int main(int argc, char const *argv[])
{
    Car c1(107);
    Car c2(999);
    Car c3(2000);
    c1.entersTrack();
    c3.entersTrack(); // a 2000-s azonosítójú autó másodikként lép pályára
    c2.entersTrack();
    std::cout << c3 << std::endl; //(*) Kiirjuk c3 adatait: "Car #2000 entered the track as the 2. car"
    if (c3 < c2)     //(**) Ha c3 előbb került pályára, mint c2
    {
        std::cout << c3.getNumber() << " entered the track earlier." << std::endl;
    }
    return 0;
}
