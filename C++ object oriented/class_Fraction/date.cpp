#include <iostream>
using namespace std;
#include <iomanip>
#include "date.h"

const int M = 12;	//number of months
static int dl[M] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const char* months[M] = { "Jan", "Feb", "Mar", "Apr","May","Jun","Jul",
						"Aug","Sep","Oct","Nov","Dec"};

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {
}

Date::Date(const char* date) {
}

bool& Date::SetFormat(bool format) {
	if (format == true) {
		operator << day << "." << month << "." << year;
	}
	else {
		operator << day << "." << months[month + 1] << "." << year;
	}
}