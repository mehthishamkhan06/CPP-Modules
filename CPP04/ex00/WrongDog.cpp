#include "WrongDog.hpp"

WrongDog::WrongDog()
{
    this->_type = "WrongDog";
    std::cout << "WrongDog default constructor called" << std::endl;
}

WrongDog::WrongDog(const WrongDog &copy) : WrongAnimal(copy)
{
    std::cout << "WrongDog copy constructor called" << std::endl;
}

WrongDog &WrongDog::operator=(const WrongDog &copy)
{
    std::cout << "WrongDog assignment operator called" << std::endl;
    if (this != &copy)
    {
        this->_type = copy._type;
    }
    return (*this);
}

WrongDog::~WrongDog()
{
    std::cout << "WrongDog destructor called" << std::endl;
}

void WrongDog::makeSound() const
{
    std::cout << "WrongDog:makeSound() called" << std::endl;
    std::cout << "Moooo!" << std::endl;
}