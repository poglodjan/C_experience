#include <iostream>
#include <string>
using namespace std;

class Organism
{
private: 
	int organismId;
	static int populationid;
	string name;

public:
	Organism(const string& _name);
	virtual ~Organism();
	int population() { return organismId; };
	static int getId() { return populationid; };
	string getName() const { return name; };
	virtual string data() const;
	friend ostream& operator<<(ostream&, const Organism&);
};	