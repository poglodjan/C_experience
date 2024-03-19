#pragma once

#include <iostream>
using namespace std;

const int NAME_SIZE = 16;

class Tram{

private:
	static int no_in_use;
	static int max_id;
	char depot_name[NAME_SIZE];
	int line_no;
	const int tram_id;
	char state; //ready, work, failure, off

public:
//fill missing
	Tram(const char * depot);
	static int getInUse();
	inline int getID();
	char getState();
	void returnDepot(const char* depot);
	void prepare(int linenumber);
	void run();

	friend ostream& operator<<(ostream& os, const Tram& t);

};

void check(Tram &t) {
	if (t.getState() == 'f') {
		t.returnDepot("Praga");
		cout << "Check: Tram : " << t << " redirected\n";
	}
	else {
		cout << "Check Tram: " << t << "OK!\n";
	}
}