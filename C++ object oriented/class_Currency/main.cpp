#include <iostream>
using namespace std;
#include "l3.h"


int main()
{
	int t = 2;


	british_currency bc;
	bc.read();
	bc.print();

	bc = add(bc, bc);
	bc.print();

	return 0;
}























