#include <iostream>
#include <string>
#include "organism.h"
using namespace std;

class Organism;

class Ecosystem
{
private:
	Organism** organisms;
	int size;
public:
	Ecosystem();
	~Ecosystem();
	bool initialize(const string& input);
	void clear();
};