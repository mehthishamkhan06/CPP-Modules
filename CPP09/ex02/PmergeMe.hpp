#ifndef PmergeMe_HPP
# define PmergeMe_HPP
#include <sstream>


#include <iostream>
#include <string>
#include <vector>
// #include <stack>
#include <climits>
#include <cstdlib>
#include <deque>
#include <algorithm>


class PmergeMe{
    private:
        void sort_vector(std::vector<int> &input);
        void sort_deque(std::deque<int> &input);
        void print_vec(double vector_duration);
        void print_deque(double deque_duration);
        void parse_input(const std::string &input);
        void binaryInsert_vector(std::vector<int>& container, int value);
        void binaryInsert_deque(std::deque<int>& container, int value);
        std::vector<int> buildInsertionSequence_vector(int pendingSize);
        std::deque<int> buildInsertionSequence_deque(int pendingSize);

        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        PmergeMe();
        PmergeMe(std::string input);
        ~PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

};

#endif