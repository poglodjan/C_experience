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

bool Library::operator+=(Book& b) {
	if (book_count < MAX_BOOKS) {
		books[book_count++] = new Book(b);
		return true;
	}
	else {
		std::cout << "Library is full, cannot add more trams." << endl;
		return false;
	}
}

// ===== STAGE  4 ===== 

Book* Library::Rent(const char* bookTitle) {
	for (int i = 0; i < book_count; i++) {
		if (books[i]->MatchTitle(bookTitle)) {
			Book* rentedBook = books[i];
			
			for (int j = i; j < book_count - 1; j++) {
				books[j] = books[j + 1];
			}
			books[book_count - 1] = nullptr;
			--book_count;
			return rentedBook;
		}
	}
	cout << "Title: " << bookTitle << " - no such book in the Library" << endl;
	return nullptr;
}

// ===== STAGE  5 ===== 

void Library::ListByAuthor(const char* athorName) {
	int foundBooks = 0;
	cout << "Author name: [" << athorName << "]" << endl;
	for (int i = 0; i < book_count; i++) {
		if (books[i]->MatchAuthor(athorName)) {
			++foundBooks;
			cout << "Book: " << *books[i] <<endl;
		}
	}
	cout << "Found a total of " << foundBooks << " books." << endl;
}

// ===== STAGE  6 ===== 

void Library::FindByPhrase(const char* Phrase) {
	int foundBooks = 0;
	cout << "Searching for Phrase: [" << Phrase << "]" << endl;
	for (int i = 0; i < book_count; i++) {
		if (books[i]->MatchPhrase(Phrase)) {
			cout << "Book: " << *books[i] << endl;
			foundBooks++;
		}
	}
	cout << "Found a total of " << foundBooks << " books." << endl;
}
