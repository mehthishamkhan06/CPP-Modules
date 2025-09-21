#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array{
    private:
        T* _array;
        size_t _size;
        class OutOfBoundException : public std::exception {
            public:
                const char* what() const throw();
        };
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &other);
        Array &operator=(const Array &other);
        ~Array();
        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;
        size_t  size() const;
};

#include "Array.tpp"


#endif