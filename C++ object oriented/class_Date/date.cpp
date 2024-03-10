#include <iostream>
using namespace std;
#include <iomanip>
#include "date.h"

const int M = 12;	 
static int dl[M] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

Date::Date(int day, int month, int year, bool format) : day(day), month(month), year(year), format(format) {
}

bool Date::ifLeep() const {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool& Date::SetFormat(bool displayFormat) {
	format = displayFormat;
	return format;
}


Date::Date(const char* date) {
	int d, m, y;
	if (sscanf_s(date, "%d.%d.%d", &d, &m, &y) == 3) {
		day = d;
		month = m;
		year = y;
		format = true;
	}
}

void Date::NextDay() {
	day++;
	if (day > dl[month - 1] || (month == 2 && day == 29 && !ifLeep()))
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 1;
			year++;
		}
	}
}

void Date::PrevDay() {
	day--;

	if (day < 1) {
		if (month > 1) {
			month--;
			day = dl[month - 1];
		}
		else if (month == 1) {
			month = 12;
			day = dl[11];
			year--;
		}
	}

	 
	if (month == 2 && day == 29 && !ifLeep()) {
		day = 28;
	}
}

void Date::SelectedDay(int days) {
	day += days;

	while (day > dl[month - 1] || (month == 2 && day == 29 && !ifLeep())) {
		day -= dl[month - 1];
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}

	while (day <= 0) {
		month--;

		if (month < 1) {
			month = 12;
			year--;
		}
		day += dl[month - 1];
	}
}

bool Date::ifEqual(const Date& other) const {
	return (day == other.day && month == other.month && year == other.year);
}
bool ifLess(const Date& d1, const Date& d2){
	if ((d1.day < d2.day && d1.month == d2.month && d1.year == d2.year) || (d1.month < d2.month && d1.year == d2.year)  || d1.year < d2.year) return 1;
	return 0;
}
bool ifMore(const Date& d1, const Date& d2) {
	if ((d1.day > d2.day && d1.month == d2.month && d1.year == d2.year) || (d1.month > d2.month && d1.year == d2.year) || d1.year > d2.year) return 1;
	return 0;
}

int NuberOfDays(const Date& startDate, const Date& endDate) {
	Date tempDate = startDate;
	int days = 0;

	while (!tempDate.ifEqual(endDate)) {
		tempDate.NextDay();
		days++;
	}
	return days;
}

ostream& operator<<(ostream& out, const Date& d) {
	if (d.format) {
		out << d.day << "." << d.month << "." << d.year << endl;
	}
	else {
		string month_alias;
		switch (d.month) {
		case 1: month_alias = "Jan"; break;
		case 2: month_alias = "Feb"; break;
		case 3: month_alias = "Mar"; break;
		case 4: month_alias = "Apr"; break;
		case 5: month_alias = "May"; break;
		case 6: month_alias = "Jun"; break;
		case 7: month_alias = "Jul"; break;
		case 8: month_alias = "Aug"; break;
		case 9: month_alias = "Sep"; break;
		case 10: month_alias = "Oct"; break;
		case 11: month_alias = "Nov"; break;
		case 12: month_alias = "Dec"; break;
		default: month_alias = "Unknown"; break;
		}
		out << month_alias << " " << d.day << "." << d.year <<endl;
	}
	return out;
}

istream& operator>>(istream& in, Date& d)
{
	do {
		cout << "Enter year (2001-2100)";
		in >> d.year;
	} while (d.year < 2001 || d.year>2100);
	do {
		cout << "Enter month (1-12)";
		in >> d.month;
	} while (d.month < 1 || d.month>12);
	do {
		cout << "Enter day";
		in >> d.day;
	} while (d.day < 1 || d.day > dl[d.month - 1] || (d.month == 2 && d.day == 29 && !d.ifLeep()));
	return in;
}

