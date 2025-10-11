#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

PmergeMe::PmergeMe(std::string input){
    this->parse_input(input);
    this->init_sorting();
}

PmergeMe::PmergeMe(const PmergeMe &copy){
    *this = copy;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
    (void)copy;
    return (*this);
}

void PmergeMe::makepair(int a, int b){
    if (a > b)
    {
        _main.push_back(a);
        _left.push_back(b);
    }
    else
    {
        _main.push_back(b);
        _left.push_back(a);
    }

}

void PmergeMe::init_sorting(){
    std::cout << "Initializing sorting..." << std::endl;
    for (size_t i = 0; i < _vector.size(); i+=2){
        makepair(_vector[i], _vector[i + 1]);
    }
    for (size_t i = 0; i < this->_main.size(); ++i)
        std::cout << _main[i] << std::endl;
}

void PmergeMe::parse_input(const std::string &input)
{
    std::stringstream ss(input);
    std::string token;
    int number = 0;

    while (ss >> token)
    {
        for (size_t i = 0; i < token.size(); ++i)
        {
            if (token[i] == '-' || token[i] == '+')
                i++;
            if (!std::isdigit(token[i]))
                throw std::runtime_error("Error: Invalid token '" + token + "'");
        }
        number = std::atoi(token.c_str());      
        if (number < 0)
            throw std::runtime_error("Error: Negative numbers not allowed");
        _vector.push_back(number);
    }
    if (_vector.empty())
        throw std::runtime_error("Error: Empty input");
}



void PmergeMe::sort(){
    std::cout << "Sorting..." << std::endl;

}