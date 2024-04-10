class Product
{
private:
    double price;
    static double sale_percent;

public:
    Product(double);

    Product& operator+=(unsigned int rhs)
    {
        price += rhs;
        return *this;
    }

    static void setSalePercent(double discount);

    double getCurrentPrice()
    {
        return price * (1 - sale_percent / 100);
    }

};