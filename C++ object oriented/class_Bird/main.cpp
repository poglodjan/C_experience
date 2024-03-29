#include <iostream>
#include <string>
#include "Bird.h"
using namespace std;

int main() 
{
	Parrot bird1(true, "Parrot bird");
	Kiwi bird2(false, "Kiwi bird");
	bird1.Fly();
	bird2.Fly();

	return 0;
}
