#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

PmergeMe::~PmergeMe(){

}

PmergeMe::PmergeMe(std::string input){
    
    this->parse_input(input);

    clock_t vector_start = clock();
    this->sort_vector(_vector);
    clock_t vector_end = clock();
    
    clock_t deque_start = clock();
    this->sort_deque(_deque);
    clock_t deque_end = clock();

    double vector_duration = (static_cast<double>(vector_end - vector_start) / CLOCKS_PER_SEC) * 10;
    double deque_duration = (static_cast<double>(deque_end - deque_start) / CLOCKS_PER_SEC) * 10;

    this->print_vec(vector_duration);
    this->print_deque(deque_duration);
}

PmergeMe::PmergeMe(const PmergeMe &copy){
    *this = copy;
}


PmergeMe &PmergeMe::operator=(const PmergeMe &copy){
    if (this != &copy)
    {
        this->_vector = copy._vector;
        this->_deque = copy._deque;
    }
    return (*this);
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
}


void PmergeMe::binaryInsert_vector(std::vector<int>& container, int value) {
    std::vector<int>::iterator insertion_point = std::lower_bound(container.begin(), container.end(), value);


    container.insert(insertion_point, value);
}

void PmergeMe::binaryInsert_deque(std::deque<int>& container, int value) {
    std::deque<int>::iterator insertion_point = std::lower_bound(container.begin(), container.end(), value);

    container.insert(insertion_point, value);
}



std::vector<int> PmergeMe::buildInsertionSequence_vector(int pendingSize) {
    std::vector<int> seq;
    if (pendingSize <= 0)
        return seq;
    std::vector<int> jacob_seq;
    int a = 1;
    int b = 1;
    while (b < pendingSize) {
        jacob_seq.push_back(b);
        int next = b + 2 * a;
        a = b;
        b = next;
    }

    int last_index = 1;
    seq.push_back(0); // First element is always 0 Speacial Case..!

    for (size_t i = 0; i < jacob_seq.size(); ++i) {
        int current = jacob_seq[i];
        for (int j = current - 1; j >= last_index; --j) {
            if (j < pendingSize)
                seq.push_back(j);
        }
        last_index = current;
    }

    for (int i = last_index; i < pendingSize; ++i) {
        seq.push_back(i);
    }

    return seq;
}

std::deque<int> PmergeMe::buildInsertionSequence_deque(int pendingSize) {
    std::deque<int> seq;
    if (pendingSize <= 0)
        return seq;
    std::deque<int> jacob_seq;
    int a = 1;
    int b = 1;
    while (b < pendingSize) {
        jacob_seq.push_back(b);
        int next = b + 2 * a;
        a = b;
        b = next;
    }

    int last_index = 1;
    seq.push_back(0); // First element is always 0 Speacial Case..!

    for (size_t i = 0; i < jacob_seq.size(); ++i) {
        int current = jacob_seq[i];
        for (int j = current - 1; j >= last_index; --j) {
            if (j < pendingSize)
                seq.push_back(j);
        }
        last_index = current;
    }

    for (int i = last_index; i < pendingSize; ++i) {
        seq.push_back(i);
    }

    return seq;
}



void PmergeMe::sort_vector(std::vector<int> &input){
    std::vector<int> main_chain;
    std::vector<int> pending;
    if (input.size() <= 1)
        return;
    for (size_t i = 0; i + 1 < input.size(); i += 2){
        int a = input[i];
        int b = input[i+1];
        if (a > b)
        {
            main_chain.push_back(a);
            pending.push_back(b);
        }
        else
        {
            main_chain.push_back(b);
            pending.push_back(a);
        }
    }
    if (input.size() % 2 != 0)
        pending.push_back(input.back());

    sort_vector(main_chain);

    std::vector<int> order = buildInsertionSequence_vector(pending.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        int idx = order[i];
        binaryInsert_vector(main_chain, pending[idx]);
    }
    input = main_chain;
}

void PmergeMe::sort_deque(std::deque<int> &input){
    std::deque<int> main_chain;
    std::deque<int> pending;
    if (input.size() <= 1)
        return;
    for (size_t i = 0; i + 1 < input.size(); i += 2){
        int a = input[i];
        int b = input[i+1];
        if (a > b)
        {
            main_chain.push_back(a);
            pending.push_back(b);
        }
        else
        {
            main_chain.push_back(b);
            pending.push_back(a);
        }
    }
    if (input.size() % 2 != 0)
        pending.push_back(input.back());
    sort_deque(main_chain);
    std::deque<int> order = buildInsertionSequence_deque(pending.size());
    for (size_t i = 0; i < order.size(); ++i)
    {
        int idx = order[i];
        binaryInsert_deque(main_chain, pending[idx]);
    }
    input = main_chain;
}

void PmergeMe::print_vec(double vector_duration){
    std::cout << "After: ";
    for(size_t i = 0; i < _vector.size(); ++i)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vector.size()
              << " elements with std::vector : " << vector_duration << " us" << std::endl;
}

void PmergeMe::print_deque(double deque_duration){
    std::cout << "Time to process a range of " << _deque.size()
              << " elements with std::deque : " << deque_duration << " us" << std::endl;
}