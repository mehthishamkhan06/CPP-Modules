#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makeSound called" << std::endl;
    std::cout << "WrongAnimal makes sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
    std::cout << "WrongAnimal getType called" << std::endl;
    std::cout << "WrongAnimal type: " << this->_type << std::endl;
    return (this->_type);
}