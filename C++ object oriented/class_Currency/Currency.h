#pragma once

class british_currency
{
	int pounds;
	int shillings;
	int pences;

public:
	british_currency(int _pounds = 0, int _shillings = 0, int _pences = 0);
	//british_currency();



	int get_pounds() const { return pounds; }
	int get_shillings() const { return shillings; }
	int get_pences() const { return pences; }

	void fix();
	void read();
	void print() const;

	friend british_currency add(const british_currency& bc1, const british_currency& bc2);
	friend ostream& operator<<(ostream& out, const british_currency& w);
	friend istream& operator>>(istream& in, british_currency& w);

};






