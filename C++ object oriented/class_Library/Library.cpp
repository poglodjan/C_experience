#include "Library.h"

using namespace std;

Library::Library() : book_count(0)  {
	for (int i = 0; i < MAX_BOOKS; i++)
	{
		books[i] = nullptr;
	}
}

ostream& operator<<(ostream& out, const Library& l) {
	out << " Library Book Count: " << l.book_count;
	return out;
}

void Library::operator+=(Book& b) {
	if (book_count < MAX_BOOKS) {
		books[book_count++] = &b;
	}
	else {
		std::cout << "Library is full, cannot add more trams." << endl;
	}
}

// ===== STAGE  4 ===== 

// ===== STAGE  5 ===== 

// ===== STAGE  6 ===== 