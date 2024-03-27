#include "Library.h"
#include <iostream>

using namespace std;

int main() 
{

	// ==================   STAGE  1  ===========================
	cout << endl << "-------------  STAGE  1  --------------" << endl;

	const char *n1 = "Brandon Sanderson";
	Author a1(n1);

	const char *n2 = "Adam Mickiewicz";
	Author a2(n2);

	const char *n3 = "Stephen King";
	Author a3(n3);

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl << endl;

	cout << "Adam Mickiewicz vs Brandon Sanderson - " << (a2 == a1 ? "EQUAL" : " NOT EQUAL") << " (EXPECTED: NOT EQUAL)" << endl;
	cout << "Brandon Sanderson vs Adam Mickiewicz - " << (a1 == a2 ? "EQUAL" : " NOT EQUAL") << " (EXPECTED: NOT EQUAL)" << endl;
	cout << "Brandon Sanderson vs Brandon Sanderson - " << (a1 == a1 ? "EQUAL" : " NOT EQUAL") << " (EXPECTED: EQUAL)" << endl;

	// ==================   STAGE  2  ===========================
	std::cout << endl << "-------------  STAGE  2  --------------" << endl;

	Author aa1[] = { a2 };
	Book b1("Dziady II", aa1, 1, 1823);

	Author aa2[] = { a2 };
	Book b2("Dziady III", aa2, 1, 1832);

	Author aa3[] = { a3 };
	Book b3("Shawshank Redemption", aa3, 1, 1982);

	Author aa4[] = { a1 };
	Book b4("Mistborn", aa4, 1, 2006);


	std::cout << b1 << endl;
	std::cout << b2 << endl;
	std::cout << b3 << endl;
	std::cout << b4 << endl << endl;

	cout << "Dziady II vs Dziady II - " << (b1 == b1 ? "EQUAL" : " NOT EQUAL") << " (EXPECTED: EQUAL)" << endl;
	cout << "Dziady II vs Dziady III - " << (b1 == b2 ? "EQUAL" : " NOT EQUAL") << " (EXPECTED: NOT EQUAL)" << endl;
	cout << "Shawshank Redemption vs Mistborn - " << (b3 == b4 ? "EQUAL" : "NOT EQUAL") << " (EXPECTED: NOT EQUAL)" << endl;
	cout << "Shawshank Redemption vs Shawshank Redemption - " << (b3 == b3 ? "EQUAL" : " NOT EQUAL") << " (EXPECTED: EQUAL)" << endl;

	// ==================   STAGE  3  ===========================
	std::cout << endl << "-------------  STAGE  3  --------------" << endl;

	Library lib;
	lib += b1;
	lib += b2;
	lib += b3;
	lib += b4;
	cout << lib << endl;

	// ==================   STAGE  4  ===========================

	std::cout << endl << "-------------  STAGE  4  --------------" << endl;
	/*
	Book* br1 = lib.Rent("Mistborn");
	if (br1 != nullptr) cout << *br1 << endl;

	Book* br2 = lib.Rent("Mistborn 2");
	if (br2 != nullptr) cout << *br2 << endl;

	cout << lib << endl;
	*/
	// ==================   STAGE  5  ===========================
	
	std::cout << endl << "-------------  STAGE  5  --------------" << endl;
	/*
	Author aa5[] = { a1, a3 };
	Book b5("Lab 6 Mix", aa5, 2, 1999); lib += b5;

	Author aa6[] = { a1, a2, a3 };
	Book b6("Lab 6 Megamix", aa6, 3, 2000); lib += b6;

	Book b7("The Shining", aa3, 1, 1977); lib += b7;
	Book b8("The Running Man", aa3, 1, 1982); lib += b8;
	Book b9("Misery", aa3, 1, 1987); lib += b9;
	Book b10("The Way of Kings", aa4, 1, 2010); lib += b10;


	lib.ListByAuthor("Stephen King");
	cout << endl;
	lib.ListByAuthor("Brandon Sanderson");
	cout << endl;
	lib.ListByAuthor("Non-existing Author");
	cout << endl;
	*/
	// ==================   STAGE  6  ===========================
	/*
	std::cout << endl << "-------------  STAGE  6  --------------" << endl;

	lib.FindByPhrase("Dziady");
	cout << endl;
	lib.FindByPhrase("The");
	cout << endl;
	lib.FindByPhrase("this for sure will not be in a title");
	cout << endl;
	*/
	return 0;
}