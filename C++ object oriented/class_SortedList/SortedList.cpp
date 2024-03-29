#include <iostream>
#include "SortedList.h"

SortedList::SortedList()
{
	head = nullptr;
}

SortedList::~SortedList()
{
	Element* ptr = head;
	while (ptr != nullptr)
	{
		head = head->next;
		delete ptr;
		ptr = head;
	}
}

SortedList::SortedList(const SortedList& s1)
{
	if (s1.head == nullptr)
	{
		head = nullptr;
		return;
	}
	head = new Element(s1.head->data, nullptr);
	Element* ptr = head;
	Element* slptr = s1.head->next;

	while (slptr != nullptr)
	{
		ptr->next = new Element(slptr->data, nullptr);
		ptr = ptr->next;
		slptr = slptr->next;
	}
}

SortedList& SortedList::operator=(const SortedList& s1)
{
	if (this == &s1) return *this;
	this->~SortedList();

	if (s1.head == nullptr)
	{
		head = nullptr;
		return *this;
	}

	head = new Element(s1.head->data, nullptr);
	Element* ptr = head;
	Element* slptr = s1.head->next;
	
	while (slptr != nullptr) 
	{
		ptr->next = new Element(slptr->data, nullptr);
		ptr = ptr->next;
		slptr = slptr->next;
	}
	return *this;
}

int SortedList::GetFirst()
{
	int p = 0;
	Element* ptr;
	if (head == nullptr) return 0;
	p = head->data;
	ptr = head;
	head = head->next;
	delete ptr;
	
	return p;
}

void SortedList::Insert(int new_data)
{
	if (head == nullptr || new_data < head->data)
	{
		head = new Element(new_data, head);
	}
	else
	{
		Element* ptr = head;
		while (ptr->next != nullptr && ptr->next->data < new_data)
		{
			ptr = ptr->next;
			ptr->next = new Element(new_data, ptr->next);
		}
	}
}

ostream& operator<<(ostream& out, const SortedList& s1)
{
	for (SortedList::Element* ptr = s1.head; ptr != nullptr; ptr = ptr->next)
	{
		out << ptr->data << " ";
	}
	out << endl;
	return out;
}
