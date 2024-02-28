#include "functions.h"
#include <iostream>

int Fraction::calculate_gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void Fraction::simplify() {
    int gcd = calculate_gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    simplify();
}

void Fraction::add(const Fraction& other) {
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
}

void Fraction::substract(const Fraction& other) {
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    simplify();
}

void Fraction::display() const {
    std::cout << numerator << '/' << denominator << std::endl;
}
