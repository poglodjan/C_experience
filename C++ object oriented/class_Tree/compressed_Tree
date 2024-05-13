// .h
using namespace std;
#include <string.h>
#include <iostream>
#include <iomanip>
#include <exception>

// class Tree
class ExprTree
{
public:
    virtual ~ExprTree() = default;
    virtual void addRight(ExprTree *child) = 0;
    virtual int calculate() const = 0;
};


// class negation
class ExprTreeNegation : public ExprTree
{
protected:
    ExprTree *child;
public:
    explicit ExprTreeNegation(ExprTree *child = nullptr);
    ~ExprTreeNegation() override;
    void addRight(ExprTree *right) override;
    int calculate() const override;    
};


// class number
class ExprTreeNumber : public ExprTree
{
protected:
    int value;
public:
    explicit ExprTreeNumber(int value);
    ~ExprTreeNumber() override = default;
    void addRight(ExprTree *child) override;
    int calculate() const override;
};


// class substraction
class ExprTreeSubtraction : public ExprTree
{
protected:
    ExprTree *left;
    ExprTree *right;
public:
    explicit ExprTreeSubtraction(ExprTree *left = nullptr, ExprTree *right = nullptr);
    ~ExprTreeSubtraction() override;
    void addRight(ExprTree *right) override;
    int calculate() const override;
};


// parser
class Parser
{
private:
    ExprTree *top;
    ExprTree *bottom;
    bool addNumberToTree(int num);
    void addMinusToTree();
    void resetTree();
public:
    Parser();
    bool parse(const std::string &input);
    ExprTree *getExpression() const;
}


// ************* methods *************

// class negation
ExprTreeNegation::ExprTreeNegation(ExprTree* child) : child(child){}
ExprTreeNegation::~ExprTreeNegation(){ delete child; }

void ExprTreeNegation::addRight(ExprTree* right) { child=right; }
int ExprTreeNegation::calculate() const
{
    return child->calculate() * -1;
}


// class number
ExprTreeNumber::ExprTreeNumber(int value) : value(value) {}
void ExprTreeNumber::addRight(ExprTree* child)
{
	throw std::logic_error("Cannot number to number!");
}
int ExprTreeNumber::calculate() const { return value; }


// class subtraction
ExprTreeSubtraction::ExprTreeSubtraction(ExprTree *left, ExprTree *right) : left(left), right(right){}
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

// parser
Parser::Parser() : top(nullptr), bottom(nullptr) {}
ExprTree *Parser::getExpression() const {return top;}

bool Parser::parse(const std::string &input)
{
    auto it = input.begin();
    std::string number;
    while(it != input.end())
    {
        if(std::isdigit(*it))
        {
            number += *it;
        }
        else if (*it == '-')
        {
            if(number!="")
            {
                addNumberToTree(std::stoi(number));
                number="";
            }
            addMinusToTree();
        }
        it++;
    }
    if (number != "")
        addNumberToTree(std::stoi(number));
    return true;
}

bool Parser::addNumberToTree(int num)
{
    ExprTree *expr = new ExprTreeNumber(num);
    if(bottom == nullptr && top ==nullptr)
    {
        top = expr;
    }
    else if(bottom == nullptr)
    {
        delete expr;
        return false;
    }
    else
    {
        bottom->addRight(expr);
        bottom = nullptr;
    }
    return true;
}

void Parser::addMinusToTree()
{
    if(bottom == nullptr && top == nullptr) {
        ExprTree *expr = new ExprTreeNegation();
        bottom = expr;
        top = bottom;
    } else if(bottom == nullptr) {
        ExprTree *expr = new ExprTreeSubtraction(top);
        top = expr;
        bottom = expr;
    } else {
        ExprTree *expr = new ExprTreeNegation();
        bottom->addRight(expr);
        bottom = expr;
    }
}

void Parser::resetTree()
{
    delete top;
    top = nullptr;
    bottom = nullptr;
}


// __________________________________________________
// _________________________ main ___________________
// __________________________________________________

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
