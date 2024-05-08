#include "expr_tree_negation.hpp"

ExprTreeNegation::ExprTreeNegation(ExprTree* child) : child(child)
{
}

ExprTreeNegation::~ExprTreeNegation()
{
	delete child;
}

void ExprTreeNegation::addRight(ExprTree* right)
{
	child = right;
}

int ExprTreeNegation::calculate() const
{
	return child->calculate() * -1;
}
