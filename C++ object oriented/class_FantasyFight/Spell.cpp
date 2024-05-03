#include "Spell.h"
using namespace std;

ostream& operator<<(ostream& os, const Spell& spell)
{
	spell.Serialize(os);
	return os;
}