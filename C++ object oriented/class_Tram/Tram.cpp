#define  _CRT_SECURE_NO_WARNINGS
#include "Tram.h"
#include <iostream>
using namespace std;

int Tram::no_in_use = 0;
int Tram::max_id = 0;

Tram::Tram(const char* depot) : tram_id(++max_id),
line_no(-1), state('o'){

	strncpy(this->depot_name, depot, NAME_SIZE);
}

void Tram::prepare(int linenumber) {
	line_no = linenumber;
	state = 'r';
}

void Tram::run() {
	no_in_use++;
	if (tram_id % 2 == 1) {
		state = 'w';
	}
	else {
		state = 'f';
	}
}

void Tram::returnDepot(const char* depot) {
	//depot_name[NAME_SIZE] = depot;
}

int Tram::getID(){
	return tram_id;
}

int Tram::getInUse(){
	return max_id;
}

char Tram::getState(){
	return state;
}

ostream& operator<<(ostream& out, const Tram& t) {
	out << "Tram: " << t.tram_id << " (" <<
		t.depot_name;

	if (t.state == 'r') {
		out << " prepared on line " << t.line_no << endl;
	}
	else if (t.state == 'w') {
		out << "Failure on line" << t.line_no << endl;
	}else if (t.state == 'f') {
		out << "Failure on line" << t.line_no << endl;
	}
	else if (t.state == 'o') {
		out << "Off on line" << t.line_no << endl;
	}
	return out;
}