#pragma once
#include <iostream>
using namespace std;

class Polygon
{
	int* sides;
	int n_sides;
	void init(int _n_sides = 0, int value = 0, int* _sides = nullptr);

public:
	Polygon();
	Polygon(int _n_sides);
	Polygon(int _n_sides, int value);
	Polygon(int _n_dides, int* _sides);
	Polygon(const Polygon&);
	Polygon& operator=(const Polygon&);
	~Polygon();

	int& operator[](int i);
	int operator[](int i) const;

	friend Polygon operator+(const Polygon&, const Polygon&);
	friend ostream& operator<<(ostream&, const Polygon&);
};

