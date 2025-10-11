#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

PmergeMe::PmergeMe(std::string input){
    this->parse_input(input);
    clock_t start = clock();
    this->sort_vector(_vector);
    clock_t end = clock();
    clock_t start1 = clock();
    this->sort_deque(_deque);
    clock_t end1 = clock();

    double duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
    
    double duration1 = static_cast<double>(end1 - start1) / CLOCKS_PER_SEC * 1000000;
    
    this->print_vec();
    this->print_deque();
    std::cout << "Time to process a range of " << _vector.size()
                  << " elements with std::vector : " << duration << " us" << std::endl;
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << duration1 << " us" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &copy){
    *this = copy;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
    (void)copy;
    return (*this);
}

void PmergeMe::binaryInsert_vector(std::vector<int>& container, int value) {
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

void PmergeMe::binaryInsert_deque(std::deque<int>& container, int value) {
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
    std::cout << "After: ";
    for(size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::print_deque(){
    std::cout << "After: ";
    for(size_t i = 0; i < _deque.size(); ++i)
        std::cout << _deque[i] << " ";
    std::cout << std::endl;
}

int PmergeMe::sort_vector(std::vector<int> &input){
    std::vector<int> main;
    std::vector<int> pend;
    if (input.size() <= 1)
        return 0;
    for (size_t i = 0; i + 1 < input.size(); i += 2){
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
    }
    if (input.size() % 2 != 0)
        pend.push_back(input.back());
    sort_vector(main);
    for (size_t i = 0; i < pend.size(); ++i)
        binaryInsert_vector(main, pend[i]);
    input = main;
    return 0;
}

int PmergeMe::sort_deque(std::deque<int> &input){
    std::deque<int> main;
    std::deque<int> pend;
    if (input.size() <= 1)
        return 0;
    for (size_t i = 0; i + 1 < input.size(); i += 2){
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
    }
    if (input.size() % 2 != 0)
        pend.push_back(input.back());
    sort_deque(main);
    for (size_t i = 0; i < pend.size(); ++i)
        binaryInsert_deque(main, pend[i]);
    input = main;
    return 0;
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
        long temp = strtol(token.c_str(), 0, 10);
        if (temp < 0)
            throw std::runtime_error("Error: Negative numbers not allowed");
        else if (temp > INT_MAX)
            throw std::runtime_error("Error: Number out of range");
        number = static_cast<int>(temp);
        _vector.push_back(number);
        _deque.push_back(number);
    }
    if (_vector.empty() || _deque.empty())
        throw std::runtime_error("Error: Empty input");
    std::cout << "Before: ";
    for(size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::cout << "Before: ";
    for(size_t i = 0; i < _deque.size(); ++i)
        std::cout << _deque[i] << " ";
    std::cout << std::endl;
}

