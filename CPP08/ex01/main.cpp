#include "Span.hpp"
#include <iostream>

// int main() {
//     try {
//         Span sp(3);  // capacity is 3

//         sp.addNumber(10);
//         sp.addNumber(25);
//         sp.addNumber(30);
//         int longest = sp.longestSpan();
//         int shortest = sp.shortestSpan();
//         std::cout << longest <<std::endl;
//         std::cout << shortest <<std::endl;
        
//         std::cout << "All numbers added successfully!" << std::endl;

//         //Error
//         sp.addNumber(40);

//     }
//     catch (std::exception &e) {
//         std::cout << "Exception caught: " << e.what() << std::endl;
//     }

//     return 0;
// }

int main()
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
    return 0;
}
