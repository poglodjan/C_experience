#include "expr_tree_number.hpp"
#include <stdexcept>


ExprTreeNumber::ExprTreeNumber(int value) : value(value)
{

}

void ExprTreeNumber::addRight(ExprTree* child)
{
	throw std::logic_error("Cannot number to number!");
}

int ExprTreeNumber::calculate() const
{
	return value;
}
