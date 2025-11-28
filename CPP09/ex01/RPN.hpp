#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<double> _stack;
        void validate(std::string rpn);
        int evaluate(std::string rpn);
    public:
        RPN();
        RPN(std::string RPN);
        ~RPN();
        RPN(const RPN &copy);
        RPN &operator=(const RPN &copy);

};

#endif