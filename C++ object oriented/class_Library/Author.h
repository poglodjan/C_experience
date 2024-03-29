#pragma once
#include <iostream>
using namespace std;

const int MAX_NAME_LEN = 30;

class Author
{
private:
	char name[MAX_NAME_LEN];

public:
	Author() { strcpy_s(name, ""); }

	// ===== STAGE  1 ===== 

	Author(const char* n);
	const char* get_name();

	friend ostream& operator<<(ostream& out, const Author& a);
	friend bool operator==(const Author&, const Author&);
	friend bool operator!=(const Author&, const Author&);
};

