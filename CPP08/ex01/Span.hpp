#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
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

        template <typename InputIterator>
        void addRange(InputIterator begin, InputIterator end)
        {
            for (InputIterator iter = begin; iter != end; ++iter) {
                if (_v.size() >= _N)
                    throw OutOfBoundException();
                _v.push_back(*iter);
            }
        }
        void addMoreNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};

#endif