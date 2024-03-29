#pragma once
#include "Book.h"
#include <iostream>

const int MAX_BOOKS = 100;

class Library
{
	int book_count;
	Book* books[MAX_BOOKS];

public:
	// ===== STAGE  3 ===== 
	Library();
	friend ostream& operator<<(ostream& out, const Library& l);
	bool operator+=(Book&);

	// ===== STAGE  4 ===== 
	Book* Rent(const char*);

	// ===== STAGE  5 ===== 
	void ListByAuthor(const char*);

	// ===== STAGE  6 ===== 
	void FindByPhrase(const char*);

	
};

