#include "Author.h"
using namespace std;

using namespace std;
// ===== STAGE  1 ===== 

Author::Author(const char* name_){
	strncpy_s(this->name, name_, MAX_NAME_LEN);
}

char Author::get_name() {
	return *name;
}

ostream& operator<<(ostream& out, const Author& a) {
	out << "[" << a.name << "]";
	return out;
}

bool operator==(const Author& r1, const Author& r2)
{
	return (r1.name == r2.name);
}

bool operator!=(const Author& r1, const Author& r2)
{
	return (r1.name != r2.name);
}
