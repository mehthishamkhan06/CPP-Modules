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
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}
