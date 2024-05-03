#include <iostream>
#include <string>
using namespace std;

class Animal : public Organism
{
public:
	Animal(const string& _name) : Organism(_name) {}
	string data() const override { return "(animal) " + Organism::data(); }
};