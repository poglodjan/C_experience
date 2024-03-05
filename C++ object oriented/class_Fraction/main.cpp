#include <iostream>
using namespace std;
#include "Date.h"


int main()
{
	cout << "----------   Part 1    -------------------------" << endl<<endl;

	Date d1;		// default: 9 3 2021
	Date d2(7);		// 7 and default: 3 2021
	Date d3(2, 8);	// 2 8 and default: 2021
	Date d4("30.12.2021");	// we assume such a format (always the same)

	cout << "d1=" << d1 << endl;
	cout << "d2=" << d2 << endl;

	/*
	d3.SetFormat() = true;	
	cout << "d3=" << d3 << endl;

	d4.SetFormat() = true;	
	cout << "d4=" << d4 << endl;
	
	cout << "Enter date: (2001<=year<=2100)"<<endl;
	cin >> d1;
	cout << "d1= " << d1 << endl;
	*/
	cout << "----------   Part 2    -------------------------" << endl<<endl;
	/*
	d4 = d1;
	for (int i = 0; i < 6; i++)
	{
		d4.NextDay();
		cout << "d4=" << d4 << endl;
	}
	*/
	cout << "----------   Part 3    -------------------------" << endl<<endl;
	/*
	for (int i = 0; i < 6; i++)
	{
		d4.PrevDay();
		cout << "d4=" << d4 << endl;
	}
	*/
	cout << "----------   Part 4    -------------------------" << endl<<endl;
	/*
	Date d5 = d4, d6;
	d5.SelectedDay();
	cout << "in a week it will be d5=" << d5 << endl;
	
	d5.SelectedDay(14);
	cout << "and in 2 weeks it will be d5=" << d5 << endl;

	d6 = d5;
	d5.SelectedDay(-21);
	cout << "and 3 weeks ago it was d5=" << d5 << endl;
	*/
	cout << "----------   Part 5    -------------------------" << endl<<endl;
	/*
	if (d5.ifEqual(d6))
		cout << "Dates: " << d5 << " and " << d6 << " are eqal " << endl;
	else
		cout << "Dates: " << d5 << " and " << d6 << " are different " << endl;

	if (ifLess(d5,d6))
		cout << "Date: " << d5 << " is earlier than " << d6 << endl;
	*/
	cout << "----------   Part 6    -------------------------" << endl<<endl;
	/*
	d5.SetFormat() = true;
	d6.SetFormat() = true;
	cout << "Days from: " << d5<< " to "<< d6<< " : "<< NuberOfDays(d5, d6) << endl;

	d5.SetFormat() = false;
	d6.SetFormat() = false;
	cout << "Days from: " << d6 << " to " << d5 << " : " << NuberOfDays(d6, d5) << endl;
	cout << "Days from: " << d5 << " to " << d5 << " : " << NuberOfDays(d5, d5) << endl;
	*/
}