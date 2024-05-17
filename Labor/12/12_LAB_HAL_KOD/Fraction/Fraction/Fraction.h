#pragma once

#include <iostream>
#include <string>
#include <exception>

const double EPSILON = 1e-6;

class FractionException : public std::exception
{
private:
    std::string message;

public:
    FractionException(const std::string &msg) : message(msg) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

class Fraction
{
private:
    // Tagvaltozok
    int wholePart;
    int numerator;
    int denominator;

public:
    // Konstruktor
    Fraction(int whole, int num, int denom);

    // Getterek
    int getWholePart() const { return wholePart; }
    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    // Egyszerusito fuggveny
    void simplify() {}

    // Konverzios operatorok: double es string
    explicit Fraction(double d);

    // Operator+ fuggveny
    Fraction operator+(const Fraction &other);

    // Konverzios konstruktor
    operator double() const;
    operator std::string() const;
    // reciprok
};
