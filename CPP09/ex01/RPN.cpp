#include "RPN.hpp"
#include <sstream>
RPN::RPN(){

}

RPN::~RPN(){

}

RPN::RPN(const RPN &copy){
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy){
    if (this != &copy)
        this->_stack = copy._stack;
    return (*this);
}

RPN::RPN(std::string rpn){
    this->validate(rpn);
    std::cout << this->evaluate(rpn) << std::endl;
}


int RPN::evaluate(std::string rpn)
{
    std::stringstream ss(rpn);
    char token;
    bool firstToken = true;
    
    while (ss >> token)
    {
        if (isdigit(token))
            this->_stack.push(token - '0');
        else if (token == '+' || token == '-' || token == '*' || token == '/')
        {
            if (firstToken)
                throw std::runtime_error("Error: First token cannot be an operator");
            if (this->_stack.size() < 2)
                throw std::runtime_error("Error: NOT ENOUGH OPERANDS");
            int b = this->_stack.top();
            this->_stack.pop();
            int a = this->_stack.top();
            this->_stack.pop();
            int res = 0;
            switch(token)
            {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    if (b == 0)
                        throw std::runtime_error("Error: Division by Zero not possible");
                    res = a / b;
                    break;
            }
            this->_stack.push(res);
        }
        else
            throw std::runtime_error("Error: Invaaaalid Tokeen");
        firstToken = false;
    }
    if (this->_stack.size() != 1)
        throw std::runtime_error("Error: Invaaaalid RPN");
    return (this->_stack.top());
}


void RPN::validate(std::string rpn)
{
    if (rpn.find_first_not_of(' ') == std::string::npos)
        throw std::runtime_error("Error: Empty input");

    std::stringstream ss(rpn);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1)
        {
            char c = token[0];
            if (!isdigit(c) && c != '+' && c != '-' && c != '*' && c != '/')
                throw std::runtime_error("Error: Invalid token");
        }
        else
            throw std::runtime_error("Error: Invalid token structure");
    }
}



