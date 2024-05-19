#pragma once
#include <iostream>
using namespace std;
#include "l11_LNode.h"

template <typename T = int>
class LList
{
public:
	LList();
	~LList();
	void insertBegin(T);
	void insertEnd(T);
	void sort();
	bool isEmpty() const;
	template <typename T>
	friend ostream& operator<<(ostream&, const LList<T>&);

private:
	LNode<T>* head;
	LNode<T>* tail;
	ostream& print(ostream&) const;
};


template <typename T>
LList<T>::LList()
{
	head = nullptr;
	tail = nullptr;
}

template <typename T>
LList<T>::~LList()
{
	if (!isEmpty())
	{
		LNode<T>* current = head;
		LNode<T>* temp;

		while (current != tail)
		{
			temp = current;
			current = current->next;
			delete temp;
		}
		delete current;
	}
}

template <typename T>
bool LList<T>::isEmpty() const
{
	if (head == nullptr && tail == nullptr)
		return true;
	else
		return false;
}

template <typename T>
void LList<T>::insertBegin(T _data)
{
	if (isEmpty())
	{
		LNode<T>* new_node = new LNode<T>(_data);
		head = new_node;
		tail = new_node;
		tail->next = head;
	}
	else
	{
		LNode<T>* new_node = new LNode<T>(_data);
		new_node->next = head;
		head = new_node;
		tail->next = head;
	}
}

template <typename T>
void LList<T>::insertEnd(T _data)
{
	if (isEmpty())
	{
		LNode<T>* new_node = new LNode<T>(_data);
		head = new_node;
		tail = new_node;
		tail->next = head;
	}
	else
	{
		LNode<T>* new_node = new LNode<T>(_data);
		tail->next = new_node;
		tail = new_node;
		tail->next = head;
	}
}

template <typename T>
void LList<T>::sort()
{
	for (LNode<T>* i = head; i->next != head; i = i->next)
	{
		LNode<T>* min_node = i;
		for (LNode<T>* j = i->next; j != head; j = j->next)
			if (j->getData() < min_node->getData())
				min_node = j;
		swap(min_node->data, i->data);
	}
}

template <typename T>
ostream& LList<T>::print(ostream& out) const
{
	if (isEmpty())
	{
		cout << "Empty list" << endl;

	}
	else
	{
		LNode<T>* current = head;

		out << "List content: ";
		while (current != tail)
		{
			out << current->data << ' ';
			current = current->next;
		}
		out << current->data << endl;
	}
	return out;
}

template <typename T>
ostream& operator<<(ostream& out, const LList<T>& l)
{
	l.print(out);
	return out;
}








