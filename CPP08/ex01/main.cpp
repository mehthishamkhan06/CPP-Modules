#include "Span.hpp"
#include <iostream>


int main()
{
    {    
        try{
            std::vector<int> vec;
            vec.push_back(6);
            vec.push_back(3);
            vec.push_back(17);
            vec.push_back(9);
            vec.push_back(11);
            Span sp2 = Span(10);
            sp2.addMoreNumbers(vec.begin(), vec.end());
            std::cout << sp2.shortestSpan() << std::endl;
            std::cout << sp2.longestSpan() << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            Span sp(10000);
    
            std::vector<int> numbers;
            for (int i = 0; i < 10000; i++) {
                numbers.push_back(std::rand());
            }
            
            sp.addMoreNumbers(numbers.begin(), numbers.end());
            std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
            std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
