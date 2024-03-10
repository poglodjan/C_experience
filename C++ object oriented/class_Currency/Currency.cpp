#include <iostream>
using namespace std;
#include "l3.h"


//british_currency::british_currency()
//{
//	pounds = 0;
//	shillings = 0;
//	pences = 0;
//}

british_currency::british_currency(int pounds, int _shillings, int _pences) : pounds(pounds), shillings(_shillings), pences(_pences)
{
	//this->pounds = pounds;
	//shillings = _shillings;
	//pences = _pences;
	fix();
}


void british_currency::fix()
{
	if (pounds < 0 || shillings < 0 || pences < 0)
	{
		pounds = shillings = pences = 0;
		return;
	}
	shillings += pences / 12;
	pences = pences % 12;
	pounds += shillings / 20;
	shillings = shillings % 20;
}

void british_currency::read()
{
	cout << "Enter pounds, shilings and pences: ";
	cin >> pounds >> shillings >> pences;
	fix();
}

void british_currency::print() const
{
	cout << pounds << "p-" << shillings << "s-" << pences << "d" << endl;
}


british_currency add(const british_currency& bc1, const british_currency& bc2)
{
	british_currency bc;
	bc.pounds = bc1.pounds + bc2.pounds;
	bc.shillings = bc1.shillings + bc2.shillings;
	bc.pences = bc1.pences + bc2.pences;

	//bc.set_pounds() = bc1.get_pounds() + bc2.get_pounds();
	//bc.set_shillings() = bc1.get_shillings() + bc2.get_shillings();
	//bc.set_pences() = bc1.get_pences() + bc2.get_pences();

	bc.fix();
	return bc;
}



ostream& operator<<(ostream& out, const british_currency& bc)
{
	out << bc.pounds << "p-" << bc.shillings << "s-" << bc.pences << "d" << endl;
	return out;
}

istream& operator>>(istream& in, british_currency& bc)
{
	cout << "Enter pounds, shilings and pences: ";
	in >> bc.pounds >> bc.shillings >> bc.pences;
	bc.fix();
	return in;
}


