#ifndef PmergeMe_HPP
# define PmergeMe_HPP
#include <sstream>


#include <iostream>
#include <string>
#include <vector>
#include <stack>

class PmergeMe{
    private:
        int sort(std::vector<int> &input);
        void init_sorting();
        void print_vec();
        void parse_input(const std::string &input);
        void binaryInsert(std::vector<int>& container, int value);
        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        PmergeMe();
        PmergeMe(std::string input);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

};

#endif