#include <iostream>
#include <string>
using namespace std;

class Plant : public Organism
{
public:
	Plant(const string& _name) : Organism(_name) {}
	string data() const override { return "(plant) " + Organism::data(); }
	string smell() const { return "neutral smell"; }
};