#include "Span.hpp"
#include <iostream>

int main() {
    try {
        Span sp(3);  // capacity is 3

        sp.addNumber(10);
        sp.addNumber(25);
        sp.addNumber(30);
        int longest = sp.longestSpan();
        int shortest = sp.shortestSpan();\
        std::cout << longest <<std::endl;
        std::cout << shortest <<std::endl;
        
        std::cout << "All numbers added successfully!" << std::endl;

        //Error
        sp.addNumber(40);

    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
