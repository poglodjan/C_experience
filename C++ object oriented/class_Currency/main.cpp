#include <iostream>
using namespace std;
#include "l5.h"

int main()
{
	british_currency bc1;
	british_currency bc2(2, 30, 30);

	cout << bc1 << endl;
	//bc2.set_type() = british_currency::currency_type::after;
	british_currency::change_type();

	cout << bc1 << endl;
	cout << bc2 << endl;

	//cout << test_conversion(british_currency(2));


	bank_deposit bd("John Smith");
	set_deposit(bd, bc2);
	//bd.set_deposit(2, 2, 2);
	//british_currency::set_type() = british_currency::currency_type::before;
	cout << bd;

	return 0;
}



