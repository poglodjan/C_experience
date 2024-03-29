#pragma once
#include <iostream>
#include "Polygon.h"


void Polygon::init(int _n_sides, int value, int* _sides) {
	n_sides = _n_sides;
	if (n_sides <= 0) {
		n_sides = 0;
		sides = nullptr;
		return;
	}

	sides = new (nothrow) int[n_sides];
	if (!sides) {
		n_sides = 0;
		return;
	}
	for (int i = 0; i < n_sides; i++) {
		if (_sides)
			sides[i] = _sides[i];
		else
			sides[i] = value;
	}
}

// constructors
Polygon::Polygon() : n_sides(0) {
	init();
}
Polygon::Polygon(int _n_sides)
{
	init(_n_sides);
}
Polygon::Polygon(int _n_sides, int value)
{
	init(_n_sides, value);
}
Polygon::Polygon(int _n_sides, int* _sides)
{
	init(_n_sides, 0, _sides);
}

Polygon::Polygon(const Polygon& p) 
{
	init(p.n_sides, 0, p.sides);
}

// operators
Polygon& Polygon::operator=(const Polygon& p) {
	if (this == &p)
		return *this;
	delete[] sides;
	init(p.n_sides, 0, p.sides);
	return *this;
}

int& Polygon::operator[](int i) {
	return sides[i];
}

int Polygon::operator[](int i) const {
	return sides[i];
}

Polygon operator+(const Polygon& p1, const Polygon& p2)
{
	Polygon p;
	if (p1.n_sides == p2.n_sides) 
	{
		p.n_sides = p1.n_sides;
		p.sides = new(nothrow) int[p.n_sides];

		for (int i = 0; i < p.n_sides; i++) {
			p.sides[i] = p1.sides[i] + p2.sides[i];
		}
	}
	return p;
}

ostream& operator<<(ostream& out, const Polygon& p) {
	out << "Polygon sides: " << p.n_sides << " and their size: ";
	for (int i = 0; i < p.n_sides; i++) {
		out << p.sides[i] << " ";
	}
	return out;
}

Polygon::~Polygon() {
	delete[] sides;
}
