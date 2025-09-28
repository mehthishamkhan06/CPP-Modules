#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP
#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>(){
    
}

template <typename T>
MutantStack<T>::~MutantStack(){
    
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack &copy): std::stack<T>(copy) {
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &copy){
    if (this != &copy){
        std::stack<T>::operator=(copy)
    }
    return (*this);
}


template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
    return (this->c.begin());
}
template <typename T>
MutantStack<T>::iterator MutantStack<T>::end(){
    return (this->c.end());
}

template <typename T>
MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.begin());
}

template <typename T>
MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.end());
}

template <typename T>
MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(){
    return (this->c.rbegin());
}
template <typename T>
MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
    return (this->c.rend());
}
template <typename T>
MutantStack<T>::const_reverse_iterator MutantStack<T>::rcbegin(){
    return (this->c.rbegin());
}

template <typename T>
MutantStack<T>::const_reverse_iterator MutantStack<T>::rcend()
{
    return (this->c.rend());
}
#endif