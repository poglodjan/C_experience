#pragma once
using namespace std;

class SortedList
{
	struct Element
	{
		int data;
		Element *next;
		Element(int d, Element *n) { data = d; next = n; }
	};

	Element* head;

public:
	SortedList();
	SortedList(const SortedList& s1);
	~SortedList();
	SortedList& operator=(const SortedList& s1);
	int GetFirst();
	void Insert(int new_data);
	friend ostream& operator<<(ostream& os, const SortedList& s1);
};
