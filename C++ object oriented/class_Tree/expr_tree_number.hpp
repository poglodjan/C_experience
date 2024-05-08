#ifndef __EXPR_TREE_NUMBER_HPP__
#define __EXPR_TREE_NUMBER_HPP__

#include "expr_tree.hpp"

/**
 * @brief A class representing a number node in the expression tree.
 */
class ExprTreeNumber : public ExprTree {
protected:
    /**
     * @brief The value of the number.
     */
    int value;
public:
    /**
     * @brief Constructor. Sets the internal member <b>value</b> to the value passed in parameter.
     * @param value Value to be assigned to the internal <b>value</b> member.
     */
    explicit ExprTreeNumber(int value);

    /**
     * @brief Just default destructor. No need for anything else since this calss has no children or pointers in
     * its members.
     */
    ~ExprTreeNumber() override = default;

    /**
     * @brief this method should not be called for this class. If it is called then there is an error in the logic of
     * the program. It throws <b>std::logic_error</b>.
     * @param child
     */
    void addRight(ExprTree *child) override;

    /**
     * @brief Return <b>value</b>.
     * @return Value of <b>value</b> member.
     */
    int calculate() const override;
};
#endif //__EXPR_TREE_NUMBER_HPP__
