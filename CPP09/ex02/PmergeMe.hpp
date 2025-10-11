#ifndef PmergeMe_HPP
# define PmergeMe_HPP
#include <sstream>


#include <iostream>
#include <string>
#include <vector>
#include <stack>

class PmergeMe{
    private:
        // int _threshold;
        void sort();
        void init_sorting();
        void makepair(int a, int b);
        void parse_input(const std::string &input);
        std::vector<int> _vector;
        std::vector<int> _main;
        std::vector<int> _left;
        std::deque<int> _deque;

    public:
        PmergeMe();
        PmergeMe(std::string input);
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);

};

#endif