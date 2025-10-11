#ifndef PMERGE_HPP
# define PMERGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>

class Pmerge{
    private:
        void sort();
        void init_sorting();
        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        Pmerge();
        Pmerge(std::string input);
        Pmerge(const Pmerge &copy);
        Pmerge &operator=(const Pmerge &copy);

};

#endif