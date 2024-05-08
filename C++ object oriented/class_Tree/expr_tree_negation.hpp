#ifndef __EXPR_TREE_NEGATION_HPP__
#define __EXPR_TREE_NEGATION_HPP__

#include "expr_tree.hpp"

/**
 * @brief A class representing a negation node in the expression tree.
 */
class ExprTreeNegation : public ExprTree {
protected:
    /**
     * @brief Pointer to the child expression.
     */
    ExprTree *child;
public:
    /**
     * @brief constructor. Sets the internal child member to the pointer passed in parameter.
     * @param child Pointer to the tree node to be assigned to the internal member <b>child</b>.
     */
    explicit ExprTreeNegation(ExprTree *child = nullptr);

    /**
     * @brief Destructor. frees/deletes the child.
     */
    ~ExprTreeNegation() override;

    /**
     * @brief Sets the internal member <b>child</b> to the pointer passed in parameter.
     * @param right Pointer to the tree node to be assigned to the internal member <b>child</b>.
     */
    void addRight(ExprTree *right) override;

    /**
     * @brief Calculates the result of the node and the whole expression under it.
     * @return Value returned by the <b>child->calculate()</b> negated (multiplied by -1).
     */
    int calculate() const override;
};
#endif //__EXPR_TREE_NEGATION_HPP__
