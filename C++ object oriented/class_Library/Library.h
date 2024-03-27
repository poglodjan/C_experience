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
	// operator+=
	friend ostream& operator<<(ostream& out, const Library& l);
	
	void operator+=(Book&);

	// ===== STAGE  4 ===== 
	// rent

	// ===== STAGE  5 ===== 
	// list by author

	// ===== STAGE  6 ===== 
	// find by phrase

	
};

