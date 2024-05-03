#include <iostream>
#include <string>
using namespace std;
#include "organism.h"

int Organism::populationid = 0;

Organism::Organism(const string& _name) : name(_name)
{
	populationid++;
	organismId = populationid;
}
Organism::~Organism() { populationid--; }

string Organism::data() const {
	string out = name + " [id:" + to_string(organismId) +
		+"] [population:" + to_string(populationid) + "]";
	return out;
}

ostream& operator<<(ostream & os, const Organism & organism) {
	os << organism.data();
	return os;
}