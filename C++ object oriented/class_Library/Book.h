#pragma once
#include <string>
#include "Author.h"

const int MAX_AUTHORS = 5;
const int MAX_TITLE = 25;

class Book
{
	// ===== STAGE  2 ===== 
	static int counter;
	int book_id;

	char title[MAX_TITLE];
	Author authors[MAX_AUTHORS];
	int authors_num;
	int publication_year;

public:
	// ===== STAGE  2 ===== 
	Book(const char* title, Author*, int, int);

	friend ostream& operator<<(ostream& out, const Book& b);
	friend bool operator==(const Book&, const Book&);
	friend bool operator!=(const Book&, const Book&);

	bool MatchTitle(const char* title) const;
	bool MatchAuthor(const char* author) const;
	bool MatchPhrase(const char* phrase) const;

	
};
