#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

// void print_vec()
// {
//     std::cout << _vector
// }
PmergeMe::PmergeMe(std::string input){
    this->parse_input(input);
    this->sort(_vector);
    this->print_vec();
}

PmergeMe::PmergeMe(const PmergeMe &copy){
    *this = copy;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
    (void)copy;
    return (*this);
}

void PmergeMe::binaryInsert(std::vector<int>& container, int value) {
    size_t left = 0, right = container.size();

    while (left < right) {
        size_t mid = (left + right) / 2;
        if (container[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }

    container.insert(container.begin() + left, value);
}

void PmergeMe::print_vec(){
    for(size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << std::endl;
}
int PmergeMe::sort(std::vector<int> &input){
    std::cout << "Sorting..." << std::endl;
    std::vector<int> main;
    std::vector<int> pend;
    if (input.size() <= 1)
        return 0;
    for (size_t i = 0; i < input.size(); i+=2){
        int a = input[i];
        int b = input[i+1];
        if (a > b)
        {
            main.push_back(a);
            pend.push_back(b);
        }
        else
        {
            main.push_back(b);
            pend.push_back(a);
        }
        if (input.size() % 2 != 0 && &b == &input.back())
            pend.push_back(b);
    }
    sort(main);
    for (size_t i = 0; i < pend.size(); ++i)
        binaryInsert(main, pend[i]);
    input = main;
    return 0;
}

void PmergeMe::init_sorting(){
    std::cout << "Initializing sorting..." << std::endl;
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
        number = std::strtol(token.c_str(), nullptr, 10);
        if (number < 0)
            throw std::runtime_error("Error: Negative numbers not allowed");
        else if (number > INT_MAX)
            throw std::runtime_error("Error: Number out of range");
        _vector.push_back(number);
    }
    if (_vector.empty())
        throw std::runtime_error("Error: Empty input");
}