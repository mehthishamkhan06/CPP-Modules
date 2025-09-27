#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){

}
~MutantStack();
MutantStack(MutantStack &copy);
MutantStack &operator=(MutantStack &copy);

#endif