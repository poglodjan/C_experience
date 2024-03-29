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

// ===== STAGE  4 ===== 

bool Book::MatchTitle(const char* title) const {
	return strcmp(this->title, title)==0;
}

// ===== STAGE  5 ===== 

bool Book::MatchAuthor(const char* author) const {
	for (int i = 0; i < authors_num; i++) {
		Author this_author = authors[i];
		if (strcmp(this_author.get_name(), author) == 0) {
			return true;
		}
	}
	return false;
}

// ===== STAGE  6 =====

bool Book::MatchPhrase(const char* Phrase) const{
	return strstr(title, Phrase) != nullptr;
}
