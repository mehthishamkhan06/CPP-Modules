#include "Identify.hpp"

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "Class Type is: A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "Type: B" << std::endl;
    else if (dynamic_cast<C *>(p))        
        std::cout << "Type: C" << std::endl;
}

void identify(Base& p)
{
    try{
        (void)dynamic_cast<A &>(p);
        std::cout << "Class Type is: A" << std::endl;
        return;
    }
    catch (const std::exception &e){}
    try{
        (void)dynamic_cast<B &>(p);
        std::cout << "Class Type is: B" << std::endl;
        return;
    }
    catch(const std::exception &e){}
    try{
        (void)dynamic_cast<C &>(p);
        std::cout << "Class Type is: C" << std::endl;
        return ;
    }
    catch(const std::exception &e){}
    return ;
}