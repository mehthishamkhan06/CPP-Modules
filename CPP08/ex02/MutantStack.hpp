#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack: public std::stack<T>{
    public:
        MutantStack();
        ~MutantStack();
        MutantStack(MutantStack &copy);
        MutantStack &operator=(MutantStack &copy);
};

#include "MutantStack.tpp"

#endif