#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    try {
        std::cout << "Found: " << *easyfind(v, 3) << std::endl;
        std::cout << "Not Found: " << *easyfind(v, 8) << std::endl;
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}