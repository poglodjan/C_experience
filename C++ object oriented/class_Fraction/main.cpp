#include "functions.h"
#include <iostream>
using namespace std;

int main() {

    int nom, den;
    cout << "Enter nominator:";
    cin >> nom;
    cout << "Enter denominator:";
    cin >> den;

    Fraction u1(nom, den);
    cout << "u1= ";
    u1.display();

    cout << "Enter nominator:";
    cin >> nom;
    cout << "Enter denominator:";
    cin >> den;

    Fraction u2(nom, den);
    cout << "u2= ";
    u2.display();

    Fraction u3 = u1;
    u3.add(u2);

    cout << "Addition of two fractions:\n";
    cout << "u3=u1+u2= ";
    u3.display();

    Fraction u4 = u1;
    u4.substract(u2);
    cout << "Substraction of two fractions:\n";
    cout << "u4=u1-u2= ";
    u4.display();

    return 0;
}
