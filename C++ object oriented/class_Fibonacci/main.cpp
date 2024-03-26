#include <iostream>
using namespace std;
#include "l5.h"

int main()
{
	Fibonacci f0;
	Fibonacci f1(5), f2(25), f3(44), f4(143), f5(144);
	std::cout << "0 = " << f0 << std::endl;
	std::cout << "5 = " << f1 << std::endl;
	std::cout << "25 = " << f2 << std::endl;
	std::cout << "44 = " << f3 << std::endl;
	std::cout << "143 = " << f4 << std::endl;
	std::cout << "144 = " << f5 << " - MAX_DECIMAL_VALUE exceeded" << std::endl;
	std::cout << std::endl;

	Fibonacci f6(""), f7("10000000000"), f8("1010101010"), f9("1001101");
	std::cout << f6 << " = " << f6() << " - empty string" << std::endl;
	std::cout << f7 << " = " << f7() << " - MAX_SIZE exceeded" << std::endl;
	std::cout << f8 << " = " << f8() << std::endl;
	std::cout << f9 << " = " << f9() << std::endl;

	return 0;
}



