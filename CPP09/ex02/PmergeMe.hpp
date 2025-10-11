#ifndef PmergeMe_HPP
# define PmergeMe_HPP
#include <sstream>


#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <climits>
#include <cstdlib>
class PmergeMe{
    private:
        int sort_vector(std::vector<int> &input);
        int sort_deque(std::deque<int> &input);
        void print_vec();
        void print_deque();
        void parse_input(const std::string &input);
        void binaryInsert_vector(std::vector<int>& container, int value);
        void binaryInsert_deque(std::deque<int>& container, int value);
        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        PmergeMe();
        PmergeMe(std::string input);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

};

#endif