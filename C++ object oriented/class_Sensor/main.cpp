#include <iostream>
using namespace std;
#include "l8.h"

int main()
{
	Sensor s1, s2, s3("Modern line");
	cout << s1 << s2 << s3;

	s1.on();
	s2.on();
	s3.on();

	cout << endl;
	cout << s1 << s2 << s3;

	cout << endl;
	cout << "Comparing s1 == s2 : " << (s1 == s2) << endl;
	cout << "Comparing s2 == s3 : " << (s2 == s3) << endl;

	cout << endl;
	s1.violation();
	s1.reset();
	s2.violation("Warnig!!!");
	s3.violation("Warnig!!!");
	s3.reset();

	cout << s1 << s2 << s3;



	MoveSensor ms1;
	cout << ms1.temperature();
	cout << ms1;

	return 0;
}
