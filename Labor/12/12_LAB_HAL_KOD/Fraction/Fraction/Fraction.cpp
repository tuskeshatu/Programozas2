#include "Fraction.h"

// Konstruktor

Fraction::Fraction(int whole, int num, int denom)
    : wholePart(whole + num / (denom == 0 ? throw FractionException("Fraction: Specified denominator is 0!") : denom)), numerator(num % denom), denominator(denom)
{

    simplify();
}

// Konverzios operatorok: double es string
Fraction::operator double() const
{
    return wholePart + static_cast<double>(numerator) / denominator;
}

Fraction::operator std::string() const
{
    return std::to_string(wholePart) + "  " + std::to_string(numerator) + "/" + std::to_string(denominator);
}

// Operator+ fuggveny
Fraction Fraction::operator+(const Fraction &other)
{
    return Fraction(wholePart + other.wholePart, numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

// Konverzios konstruktor
Fraction::Fraction(double d)
    : wholePart(static_cast<int>(d)), numerator((d - wholePart) / EPSILON), denominator(1.0f / EPSILON)
{
    simplify();
}