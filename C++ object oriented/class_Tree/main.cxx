#include <iostream>
#include "parser.hpp"
#include "expr_tree.hpp"
#include "expr_tree_number.hpp"
#include "expr_tree_negation.hpp"
#include "expr_tree_subtraction.hpp"

int main() {
    /*
    Create a single number and print result of calculation of this number
    */
    
    ExprTreeNumber number(5);
    std::cout << "Expected result: 5" << std::endl;
    std::cout << "Result: " << number.calculate() << std::endl;
    
    /*
    Create a single number but notice that we assign a pointer of the derived
    calss to the pointer of the base class.
    */
    
    ExprTree *x = new ExprTreeNumber(3);
    std::cout << "Expected result: 3" << std::endl;
    std::cout << "Result: " << x->calculate() << std::endl;
    delete x;
    
    /*
    Create negation and the number
    */
    
    ExprTree *num = new ExprTreeNumber(6);
    ExprTree *neg = new ExprTreeNegation(num);
    std::cout << "Expected result: -6" << std::endl;
    std::cout << "Result: " << neg->calculate() << std::endl;
    //it should delete first num, and then neg.
    delete neg;
    
    /*
    Create a subtraction of 2 numbers
    */
    
    ExprTree *num1 = new ExprTreeNumber(6);
    ExprTree *num2 = new ExprTreeNumber(4);
    ExprTree *sub = new ExprTreeSubtraction(num1, num2);
    std::cout << "Expected result: 2" << std::endl;
    std::cout << "Result: " << sub->calculate() << std::endl;
    delete sub;
    /*
    it should delete first num1, then num2, and then sub.
    delete sub;
    */

    
    std::string expression;
    std::cout << "This is a calculator of negative arithmetic expressions."
              << std::endl << "It accepts only numbers and - operator."
              << std::endl << "For example such expression: "
              << "'   -- ---23- 3  ---- -3-3  ' should evaluate to -32."
              << std::endl;
    std::cout << "Input expression to compute:" << std::endl;
    std::getline(std::cin, expression);
    Parser parser;
    if(!parser.parse(expression)) {
        std::cout << "The expression is incorrect." << std::endl;
        return 1;
    }
    ExprTree *tree = parser.getExpression();
    std::cout << "Result: " << tree->calculate() << std::endl;
    delete tree;
    
    return 0;
}
