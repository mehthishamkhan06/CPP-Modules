#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class NoOccuranceFound : public std::exception {
public:
    const char* what() const throw() {
        return "Value not found in container!";
    }
};

template <typename T>
typename T::iterator easyfind(T &container, int n);

#include "easyfind.tpp"

#endif