#ifndef __EXPR_TREE_HPP__
#define __EXPR_TREE_HPP__

/**
 * @brief Abstract class defining the interface of all of the nodes of the expression tree.
 * All classes implementing nodes of expression tree should derive from this class.
 */
class ExprTree {
public:
    /**
     * @brief Default destructor. Destructors in subclasses should free/delete their children.
     */
    virtual ~ExprTree() = default;

    /**
     * @brief Sets the the last (right) child of the node to the child passed in the parameter.
     *
     * It is used by the parser, which needs only to set children the most to the right. The "left" ones are created
     * differently by the parser.
     * In case of nodes without children, like a number node, this method should throw an exception.
     * In case of nodes with only one child this child should be set to the pointer passed in the parameter.
     * In case of nodes with 2 children the right one should be set to the one passed in the parameter.
     * @param child The pointer to be assigned to the last (right) child of the node.
     */
    virtual void addRight(ExprTree *child) = 0;

    /**
     * @brief Calculates the expression represented by this node and the whole subtree under this node.
     * @return The result of expression represented as this node and a tree below it.
     */
    virtual int calculate() const = 0;
};
#endif //__EXPR_TREE_HPP__
