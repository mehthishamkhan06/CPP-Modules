#include "Span.hpp"

Span::Span(){}

Span::Span(unsigned int num): _N(num){

}
Span::Span(const Span &other): _N(other._N), _v(other._v){}

Span& Span::operator=(const Span &other){
    if (this != &other)
    {
        _N = other._N;
        _v = other._v;
    }
    return (*this);
}

Span::~Span(){

}

void Span::addNumber(int n){
    if (_v.size() >= _N)
        throw OutOfBoundException();
    _v.push_back(n);
}

const char* Span::OutOfBoundException::what() const throw(){
    return ("OutOfBound..!");
}

int Span::longestSpan() const{
    if(_v.size() < 2)
        throw OutOfBoundException();
    return(*std::max_element(_v.begin(), _v.end()) - *std::min_element(_v.begin(), _v.end()));
}

int Span::shortestSpan() const{
    std::vector<int> temp = _v;
    if (temp.size() < 2)
        throw OutOfBoundException();
    std::sort(temp.begin(), temp.end());
    std::adjacent_difference(temp.begin(), temp.end(), temp.begin());
    return (*std::min_element(temp.begin() + 1, temp.end()));
}
