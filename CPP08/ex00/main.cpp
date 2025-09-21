#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    std::list<int> l;
    l.push_back(5);
    l.push_back(6);
    l.push_back(7);
    l.push_back(8);
    l.push_back(9);

    try {
        std::cout << "Found: " << *easyfind(v, 3) << std::endl;
        std::cout << "Not Found: " << *easyfind(v, 8) << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try {
        std::cout << "Found: " << *easyfind(l, 8) << std::endl;
        std::cout << "Not Found: " << *easyfind(l, 19) << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}