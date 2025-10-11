#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>

class Span {
    private:
        unsigned int _N;
        std::vector<int> _v;
        class OutOfBoundException : public std::exception {
            public:
                const char* what() const throw();
        };
    public:
        Span();
        Span(unsigned int num);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        
        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;

        template<typename t>
        void addMoreNumbers(t begin, t end){
            if (_v.size() + std::distance(begin, end) > _N)
                throw OutOfBoundException();
            _v.insert(_v.end(), begin, end);
        }
};

#endif