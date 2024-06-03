#ifndef _SET_H_
#define _SET_H_

#include <iostream>

using namespace std;

template <typename T = int>
class Set;

template <typename T>
class Node {
    T data;
    Node<T>* next;
public:
    Node(T d, Node<T>* n = nullptr) : data(d), next(n) {}
    friend class Set<T>;
};

template <typename T>
class Set {
    Node<T>* begin;
public:
    Set();
    ~Set();
    Set(const Set<T>&);
    Set<T>& operator=(const Set<T>&);

    bool isEmpty() const { return begin == nullptr; }
    bool inSet(T) const;
    void insert(T);
    void free();
    void copyFrom(const Set<T>&);
    T pop();
    void print(ostream&) const;

    friend ostream& operator<< <T>(ostream&, const Set<T>&);
    friend Set<T> operator+<T>(const Set<T>&, const Set<T>&);
	friend Set<T> operator-<T>(const Set<T>&, const Set<T>&);
};

template <typename T>
Set<T>::Set() : begin(nullptr) {}

template <typename T>
Set<T>::~Set() {
	free();
}

template <typename T>
Set<T>::Set(const Set<T>& s) : begin(nullptr) {
	copyFrom(s);
}

template <typename T>
void Set<T>::free() {
	while (begin) {
		Node<T>* tmp = begin->next;
		delete begin;
		begin = tmp;
	}
	begin = nullptr;
}

template <typename T>
bool Set<T>::inSet(T v) const {
	if constexpr (std::is_same_v<T, char>) {
		// dla typu char
		Node<T>* tmp = begin;
		while (tmp) {
			if (tolower(tmp->data) == tolower(v))
				return true;
			tmp = tmp->next;
		}
		return false;
	}
	else {
		// dla innych typów
		Node<T>* tmp = begin;
		while (tmp) {
			if (tmp->data == v)
				return true;
			tmp = tmp->next;
		}
		return false;
	}
}


template <typename T>
void Set<T>::copyFrom(const Set<T>& s) {
	Node<T>* tmp = s.begin;
	while (tmp) {
		insert(tmp->data);
		tmp = tmp->next;
	}
}
template <typename T>
Set<T>& Set<T>::operator=(const Set<T>& s) {
	if (&s != this) {
		free();
		copyFrom(s);
	}
	return *this;
}

template <typename T>
void Set<T>::insert(T d) {
	if (inSet(d)) {
		cout << "Already in set, no insert" << endl;
		return;
	}
	try {
		if (begin == nullptr) {
			begin = new (nothrow) Node<T>(d);
		}
		else {
			begin = new (nothrow) Node<T>(d, begin);
		}
	}
	catch (const bad_alloc& e)
	{
		cerr << "Memory alloc error :( : " << e.what() << endl;
	}

}

template <typename T>
T Set<T>::pop() {
	if (isEmpty())
	{
		throw out_of_range("Set is empty, cannot pop! :)");
	}
	Node<T>* tmp = begin;
	begin = begin->next;
	T d = tmp->data;
	delete tmp;
	return d;
}

template <typename T>
void Set<T>::print(ostream& os) const {
	Node<T>* tmp = begin;
	while (tmp) {
		os << tmp->data << " ";
		tmp = tmp->next;
	}
}

template <typename T>
ostream& operator<<(ostream& os, const Set<T>& s) {
	s.print(os);
	return os;
}

template <typename T>
Set<T> operator+(const Set<T>& lh, const Set<T>& rh) // suma zbiorow
{
	Set<T> S = lh;
	S.copyFrom(rh);
	return S;
}

template <typename T>
Set<T> operator-(const Set<T>& lh, const Set<T>& rh) {
	Set<T> result; // Tworzymy nowy zbiór wynikowy

	// Kopiujemy zawartość zbioru lh do zbioru wynikowego
	Set<T> temp = lh;
	Node<T>* tmp = temp.begin;
	while (tmp) {
		// Jeśli element z zbioru lh nie istnieje w zbiorze rh, dodajemy go do zbioru wynikowego
		if (!rh.inSet(tmp->data)) {
			result.insert(tmp->data);
		}
		tmp = tmp->next;
	}

	return result;
}



#endif //_SET_H_
