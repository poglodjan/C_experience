#pragma once

class Fraction {
private:
    int numerator;
    int denominator;

    int calculate_gcd(int a, int b);
    void simplify();

public:
    Fraction(int num, int denom);

    void add(const Fraction& other);
    void substract(const Fraction& other);
    void display() const;
};

