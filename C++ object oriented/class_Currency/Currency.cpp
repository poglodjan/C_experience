#include <iostream>
#include <iomanip>
using namespace std;
#include "l5.h"

british_currency::currency_type british_currency::type = british_currency::currency_type::before;

british_currency::british_currency(int pounds, int shillings, int pences, const char* symbol) : pounds(pounds), shillings(shillings), pences(pences), symbol(symbol)
{
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


void british_currency::read(istream& in)
{
	cout << "Enter pounds, shilings and pences: ";
	in >> pounds >> shillings >> pences;
	fix();
}


void british_currency::print(ostream& out) const
{
	if (type == currency_type::before)
		out << pounds << "p-" << shillings << "s-" << pences << "d" << endl;
	else
		out << setprecision(3) << (*this)() << symbol << endl;

}

british_currency add(const british_currency& bc1, const british_currency& bc2)
{
	british_currency bc;
	bc.pounds = bc1.pounds + bc2.pounds;
	bc.shillings = bc1.shillings + bc2.shillings;
	bc.pences = bc1.pences + bc2.pences;

	bc.fix();
	return bc;
}

british_currency operator+(const british_currency& bc1, const british_currency& bc2)
{
	british_currency bc;
	bc.pounds = bc1.pounds + bc2.pounds;
	bc.shillings = bc1.shillings + bc2.shillings;
	bc.pences = bc1.pences + bc2.pences;

	bc.fix();
	return bc;
}

british_currency operator+(const british_currency& bc1, const int& d)
{
	british_currency bc;
	bc.pounds = bc1.pounds;
	bc.shillings = bc1.shillings;
	bc.pences = bc1.pences + d;
	bc.fix();
	return bc;
}

british_currency operator+(const int& d, const british_currency& bc1)
{
	british_currency bc;
	bc.pounds = bc1.pounds;
	bc.shillings = bc1.shillings;
	bc.pences = bc1.pences + d;
	bc.fix();
	return bc;
}

ostream& operator<<(ostream& out, const british_currency& bc)
{
	bc.print(out);
	return out;
}

istream& operator>>(istream& in, british_currency& bc)
{
	bc.read(in);
	return in;
}

void british_currency::to_pences()
{
	pences += ((pounds * 20) + shillings) * 12;
	pounds = shillings = 0;
}

int british_currency::no_of_pences() const
{
	return pences + ((pounds * 20) + shillings) * 12;
}


british_currency& british_currency::operator-=(const british_currency& bc2)
{
	//if (w.pences > pences)
	//{
	//	pences += 12;
	//	shillings--;
	//}
	//pences -= w.pences;
	//if (w.shillings > shillings)
	//{
	//	shillings += 20;
	//	pounds--;
	//}
	//shillings -= w.shillings;
	//pounds -= w.pounds;
	//fix();
	//return *this;

	// or

	to_pences();
	pences -= bc2.no_of_pences();
	fix();
	return (*this);
}


british_currency& british_currency::operator++() // prefix (++w)
{
	pences++;
	fix();
	return *this;
}


british_currency british_currency::operator++(int) // postix (w++)
{
	british_currency temp(*this);

	pences++;
	fix();

	return temp;
}


double british_currency::operator()() const
{
	return static_cast<double>(no_of_pences()) / 240;
}


void british_currency::change_type()
{
	if (type == currency_type::before)
		type = currency_type::after;
	else
		type = currency_type::before;
}


double test_conversion(const british_currency& bc)
{
	//return 2.0;
	//return (bc);
	return (double)(bc);
	return static_cast<double>(bc);
}

british_currency::operator double() const
{
	//return double(pences + ((pounds * 20) + shillings) * 12) / 240;
	return this->operator()();
}



british_currency::currency_symbol::currency_symbol(const char* symbol)
{
	strcpy_s(this->currency_mark, symbol);
}

ostream& operator<<(ostream& out, const british_currency::currency_symbol& cs)
{
	out << cs.currency_mark;
	return out;
}


// Bank Deposit

bank_deposit::bank_deposit(const char* name)
{
	strcpy(this->name, name);
}

ostream& operator<<(ostream& out, const bank_deposit& bd)
{
	out << "Name: " << bd.name << " Deposit value: " << bd.deposit << endl;
	return out;
}


void set_deposit(bank_deposit& bd, british_currency& dep)
{
	bd.deposit = dep;
}


void bank_deposit::set_deposit(int pounds, int shillings, int pences)
{
	deposit.pounds = pounds;
	deposit.shillings = shillings;
	deposit.pences = pences;
}
