#pragma once


class british_currency
{
public:
	friend class bank_deposit;

	enum class currency_type { before = 1, after };

	class currency_symbol
	{
		static constexpr int symbol_length = 4;
		char currency_mark[symbol_length];
	public:
		currency_symbol() : currency_mark("GBP") {};
		currency_symbol(const char* symbol);
		friend ostream& operator<<(ostream& out, const british_currency::currency_symbol& cs);
	};

private:
	int pounds = 0;
	int shillings = 0;
	int pences = 0;
	//currency_type type = currency_type::before; // not currency_type type = 1;
	static currency_type type;
	//static const int symbol_length = 4;
	//char symbol[symbol_length];
	//const char* symbol;
	currency_symbol symbol;
	

public:
	//british_currency(int _pounds = 0, int _shillings = 0, int _pences = 0);
	explicit british_currency(int pounds = 0, int shillings = 0, int pences = 0, const char* symbol = "GBP");

	int get_pounds() const { return pounds; }
	int get_shillings() const { return shillings; }
	int get_pences() const { return pences; }

	void set_pounds(int _pounds) { pounds = _pounds; }
	void set_shillings(int _shillings) { shillings = _shillings; }
	void set_pences(int _pences) { pences = _pences; }

	//currency_type& set_type() { return type; };
	static void change_type();

	explicit operator double() const;

	void fix();
	void to_pences();
	int no_of_pences() const;

	void read(istream& in);
	void print(ostream& out) const;

	friend british_currency add(const british_currency& bc1, const british_currency& bc2);

	friend british_currency operator+(const british_currency& bc1, const british_currency& bc2);
	friend british_currency operator+(const british_currency& bc1, const int& d);
	friend british_currency operator+(const int& d, const british_currency& bc1);

	british_currency& operator-=(const british_currency& w);

	friend ostream& operator<<(ostream& out, const british_currency& w);
	friend istream& operator>>(istream& in, british_currency& w);

	british_currency& operator++(); // prefix (++w)
	british_currency operator++(int);  // postix (w++)

	double operator()() const;


};


double test_conversion(const british_currency& bc);



class bank_deposit
{
	static constexpr int MAX_NAME_LENGTH = 20;
	char name[MAX_NAME_LENGTH];
	british_currency deposit;
public:

	bank_deposit(const char* name);

	void set_deposit(int pounds = 0, int shillings = 0, int pences = 0);

	friend ostream& operator<<(ostream& out, const bank_deposit& bd);
	friend void set_deposit(bank_deposit& bd, british_currency& dep); // friendship 
};
