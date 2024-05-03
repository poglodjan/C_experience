#include <iostream>
#include <string>
using namespace std;

class Rose : public Plant
{
public:
	Rose() : Plant("rose") {};
	string smell(bool is_intensive) const
	{
		if (is_intensive) return "strong rose scent";
		else return "slightly rose fragrance";
	};
	string smell() const
	{
		return Plant::smell();
	};
};