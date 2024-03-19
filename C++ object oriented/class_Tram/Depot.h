#pragma once

#include "Tram.h"

const int MAX_TRAMS = 20;
const int MAX_ = 32;

class Depot{

	Tram * atbase[MAX_TRAMS];
	int num;
	char depot_id[MAX_];

public:
 //fill missing
	Depot(const char* name);

	void operator+=(Tram &);
	void send_first();

	int atBase();

	friend ostream& operator<<(ostream& out, const Depot& d);
};
