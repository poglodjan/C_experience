#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include <string>
#include "expr_tree.hpp"

/**
 * @brief Simple parser which accepts as input string with integer numbers, minus operators (-) and whitespace and
 * create an expression tree representing the parsed expression.
 */
class Parser {
private:
    /**
     * @brief The current root of the expression tree.
     *
     * It is used also to construct the tree from the top.
     */
    ExprTree *top;

    /**
     * @brief The pointer to the leaf node that has a child that is not yet defined (the child is set to nullptr).
     *
     * It is used to construct the expression from the bottom.
     */
    ExprTree *bottom;

    /**
     * @brief Creates the number node and adds it to the expression tree. The node is added to the bottom of the tree.
     * @param num The value of the number to be set in the node.
     * @return True if it was possible to add a node with the number to the tree, false otherwise.
     */
    bool addNumberToTree(int num);

    /**
     * @brief Creates and adds a negation or a subtraction node to the tree. If there is a place for a new node in
     * the bottom of the tree then the node is inserted at the bottom as negation. If not, then the node is inserted
     * at the top of the tree as subtraction.
     */
    void addMinusToTree();

    /**
     * @brief Deletes the whole tree and sets <b>top</b> and <b>bottom</b> pointers to nullptr. this is the state
     * before starting the parsing.
     */
    void resetTree();
public:
    /**
     * @brief Constructor. Initializes internal pointers to nullptr.
     */
    Parser();

    /**
     * @brief Parses input string and builds the expression tree.
     * @param input The string with expression to be parsed.
     * @return True if expression was correct and parsing succeeded, false otherwise.
     */
    bool parse(const std::string &input);

    /**
     * @brief Getter for expression tree.
     * @return Pointer to the root of the expression tree built during parsing.
     */
    ExprTree *getExpression() const;
};
#endif //__PARSER_HPP__
