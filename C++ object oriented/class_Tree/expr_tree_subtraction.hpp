#ifndef __EXPR_TREE_SUBTRACTION_HPP__
#define __EXPR_TREE_SUBTRACTION_HPP__

#include "expr_tree.hpp"

/**
 * @brief A class representing a subtraction node in the expression tree.
 */
 class ExprTreeSubtraction : public ExprTree {
protected:
    /**
     * The left child of the subtraction expression. result = left - right
     */
    ExprTree *left;
     /**
      * The right child of the subtraction expression. result = left - right
      */
    ExprTree *right;
public:
     /**
      * @brief
      * @param left
      * @param right
      */
    /**
     * @brief constructor. Sets the internal <b>left</b> and <b>right</b> members to the pointers passed in parameters.
     * @param left Pointer to the tree node to be assigned to the internal member <b>left</b>.
     * @param right Pointer to the tree node to be assigned to the internal member <b>right</b>.
     */
    explicit ExprTreeSubtraction(ExprTree *left = nullptr, ExprTree *right = nullptr);

    /**
     * @brief Destructor. Free/delete both children.
     */
    ~ExprTreeSubtraction() override;

     /**
     * @brief Sets the internal member <b>right</b> to the pointer passed in parameter.
     * @param right Pointer to the tree node to be assigned to the internal member <b>right</b>.
     */
    void addRight(ExprTree *right) override;

    /**
     * @brief Calculates the result of the node and the whole expression under it.
     * @return The difference between the value returned by the calculate() method called on the left child and
     * the value returned by the calculate() method called on the right child.
     */
    int calculate() const override;
};
#endif //__EXPR_TREE_SUBTRACTION_HPP__
