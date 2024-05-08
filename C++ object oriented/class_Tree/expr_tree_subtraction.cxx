#include "expr_tree_subtraction.hpp"

ExprTreeSubtraction::ExprTreeSubtraction(ExprTree* left, ExprTree* right):left(left), right(right)
{
}

ExprTreeSubtraction::~ExprTreeSubtraction()
{
	delete left;
	delete right;
}

void ExprTreeSubtraction::addRight(ExprTree* right)
{
	this->right = right;
}

int ExprTreeSubtraction::calculate() const
{
	return left->calculate() - right->calculate();
}
