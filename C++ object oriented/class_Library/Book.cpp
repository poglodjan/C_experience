#include "Book.h"
using namespace std;

int Book::counter = 0;

Book::Book(const char* tittle, Author* a, int authors_num, int year) : book_id(++counter) {
	strncpy_s(this->title, tittle, MAX_TITLE);
	this->publication_year = year;
	this->authors_num = authors_num;

	for (int i = 0; i < authors_num; i++) {
		Author a_i = a[i];
		this->authors[i] = a_i;
	}
}

bool operator==(const Book& r1, const Book& r2)
{
	if (r1.title == r2.title && r1.publication_year == r2.publication_year) {
		for (int i = 0; i < min(r1.authors_num, r2.authors_num); i++) 
		{
			if (r1.authors[i] != r1.authors[i])
			{
				return false;
			}
			return true;
		}
	}
	else
	{
		return false;
	}
}

bool operator!=(const Book& r1, const Book& r2)
{
	if (r1.title != r2.title && r1.publication_year != r2.publication_year) {
		for (int i = 0; i < min(r1.authors_num, r2.authors_num); i++)
		{
			if (r1.authors[i] != r1.authors[i])
			{
				return false;
			}
			return true;
		}
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream& out, const Book& b) {
	out << "[" << b.book_id << "] " << b.title << " by ";
	for (int i = 0; i < b.authors_num; i++)
	{
		out << b.authors[i] << " ";
	}
	out << "- " << b.publication_year;
	return out;
}


// ===== STAGE  2 ===== 

// ===== STAGE  4 ===== 

// ===== STAGE  5 ===== 

// ===== STAGE  6 ===== 