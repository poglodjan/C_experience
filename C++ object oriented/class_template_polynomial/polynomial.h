#include <iostream> 
using namespace std;

template<typename T = double>
class Function
{
public:
	Function() = default;
	Function(const Function&) = delete;
	Function& operator=(const Function&) = delete;

	virtual T value(T x) const = 0;
	virtual T prim(T x) const = 0;
	virtual ~Function() {};		
};

template<typename T = double>
class Const: public Function<T>
{
	T stala;
public:
	Const(T stala) : stala(stala) {}
	T value(T x) const override{ return stala; }
	T prim(T x) const override{ return 0; }
};

template<typename T = double>
class X: public Function<T>
{
public:
	T value(T x) const override{return x;}
	T prim(T x) const override{return 1;}
};

template<typename T = double>
class Plus : public Function<T>
{
	Function<T>* f1;
	Function<T>* f2;
public:
	Plus(Function<T>* f1, Function<T>* f2) : f1(f1), f2(f2) {}

	T value(T x) const override
	{
		return f1->value(x) + f2->value(x);
	}

	T prim(T x) const override
	{
		return f1->prim(x) + f2->prim(x);
	}

	~Plus(){delete f1;delete f2;}
};

template<typename T = double>
class Minus : public Function<T>
{
	Function<T>* f1;
	Function<T>* f2;
public:
	Minus(Function<T>* f1, Function<T>* f2) : f1(f1), f2(f2) {}

	T value(T x) const override
	{
		return f1->value(x) - f2->value(x);
	}

	T prim(T x) const override
	{
		return f1->prim(x) - f2->prim(x);
	}

	~Plus(){delete f1;delete f2;}
};

template<typename T = double>
class Iloczyn : public Function<T>
{
	Function<T>* f1;
	Function<T>* f2;
public:
	Iloczyn(Function<T>* f1, Function<T>* f2) : f1(f1), f2(f2) {}

	T value(T x) const override
	{
		return f1->value(x) * f2->value(x);
	}

	T prim(T x) const override
	{
		return f1->prim(x) * f2->value(x) + f1->value(x) * f2->prim(x);
	}

	~Plus(){delete f1;delete f2;}
};

template<typename T = double>
class Wielomian : public Function<T>
{
	Function<T>* f;
public:
	Wielomian() : f(nullptr) {}

	T value(T x) const override { return f->value(x); }
	T prim(T x) const override { return f->prim(x); }

	void generuj1(T* tab, const int n) // Horner
	{
		delete f;
		f = new Const<T>(tab[n-1]);
		for(int i = n-2; i>=0; i--)
		{
			f = new Iloczyn<T>(new X<T>(), f);
			f = new Plus<T>(new Const<T>(tab[i]),f);
		}
	}

	void generuj2(T* tab, const int n) // tablica zer wielomianu
	{
		delete f;
		Function<T>* g = new Const<T>(1);
		for(int i=0; i<n; i++)
		{
			g = new Iloczyn<T>(g, new Minus<T>(New X<T>(), new Const<T>(tab[i])));
		}
		f=g;
	}

	~Wielomian() { delete f; }
};
