#pragma once

class Date
{
private:
	int day;
	int month;
	int year;
	
	bool format;
	bool ifLeep() const;
	
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

public:
	Date(int day=1, int month=1, int year=2001);
	Date(const char* date);

	bool& SetFormat(bool format);

	
	

};



