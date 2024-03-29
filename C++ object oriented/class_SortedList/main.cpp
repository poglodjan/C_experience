#include <iostream>
#include "SortedList.h"
using namespace std;

int main() {

	SortedList s;
	s.Insert(4);
	s.Insert(3);
	s.Insert(9);

	cout << s;

	cout << s.GetFirst();

	return 0;
}
