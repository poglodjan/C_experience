#pragma once

class Date
{
private:
	int day;
	int month;
	int year;
	
	bool format;
	bool ifLeep() const;
	
	friend ostream& operator<<(ostream &, const Date&);
	friend istream& operator>>(istream &, Date&);

public:
	Date(int day = 1, int month = 1, int year = 2001, bool format = true);
	Date(const char* date);

	void NextDay();
	void PrevDay();
	void SelectedDay(int days=7);
	bool ifEqual(const Date& other) const;
	friend bool ifLess(const Date& d1, const Date& d2);
	friend bool ifMore(const Date& d1, const Date& d2);
	friend int NuberOfDays(const Date& d1, const Date& d2);
	bool& SetFormat(bool displayFormat = true);

};



