#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}
Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this != &copy)
        this->_type = copy._type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal makeSound called" << std::endl;
    std::cout << "Animal makes sound" << std::endl;
}

std::string Animal::getType() const
{
    std::cout << "Animal getType called" << std::endl;
    std::cout << "Animal type: " << this->_type << std::endl;
    return (this->_type);
}