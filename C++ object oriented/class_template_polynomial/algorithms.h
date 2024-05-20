#include <complex>
#include "polynomial.h"

using std::complex;
using std::endl;
using std::endl;

template <typename T>
T pierwiastek(const Function<T>& f, T x, int& it) throw(...);

template <int N>
void fraktal(const Function<complex<double>>& f,  const complex<double>& q) noexcept;

template <typename T>
T pierwiastek(const Function<T>& f, T x, int& it) throw(...)
{
	double eps = 1e-6;
	int max_it = 50;

	for(it = 0; it<=max_it; it++)
	{
		if (abs(f.value(x)) < eps) return x;
		if (abs(f.prim(x)) < eps) throw "Brak zbieznosci";

		x-=f.value(x) / f.prim(x);
	}

	throw "Brak zbieznosci";
}
