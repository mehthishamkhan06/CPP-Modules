#include "RPN.hpp"


int main(int ac, char *argv[])
{
    if (ac != 2)
    {
        std::cerr << "Invalid Arguments:"<< std::endl;
        return (1);
    }
    try{
        RPN rpn(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return (0);
}