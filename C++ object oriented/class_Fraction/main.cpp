#include <iostream>
using namespace std;
#include "fraction.h"
  

int main()
{
	Fraction u1, u2;

	u1.read();
	cout << "u1= ";
	u1.write();

	u2.read();
	cout << "u2= ";
	u2.write();

	cout << endl << "Addition of two fractions:" << endl;
	Fraction u3 = add(u1,u2);
	cout << endl << "u3=u1+u2= ";
	u3.write();

	cout << endl << "u2+u2= ";
	add(u2,u2).write();

	cin >> u1 >> u2;
	cout << u1 << u2 << endl;

	// Fraction u4(8, -10);
	// cout << u4;

	cout << endl;
	
}
