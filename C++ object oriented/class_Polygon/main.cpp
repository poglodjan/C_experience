#include <iostream>
using namespace std;
#include "Polygon.h"

int main()
{
	int _sides[3] = { 2,3,4 };
	Polygon p;
	Polygon p1(3);
	Polygon p2(3, _sides);
	p = p1;
	p[0] = p[1] = p[2] = 1;
	cout << p << endl << p1 << endl << p2 << endl << p + p2 << endl;
	
	Polygon p3(p1);
	cout << p3;

	return 0;
}



