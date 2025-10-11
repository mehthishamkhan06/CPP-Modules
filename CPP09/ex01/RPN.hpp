#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    private:
        std::stack<std::string> rpn; 
    public:
        RPN();
        ~RPN();
        RPN(RPN &copy);
        RPN &operator=(RPN &copy);

};

#endif