#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
    this->_type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_brain = new Brain(*copy._brain);
    this->_type = copy._type;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copy)
    {
        Animal::operator=(copy);
        delete this->_brain;
        this->_brain = new Brain(*copy._brain);

        this->_type = copy._type;
    }
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->_brain; // Free the brain memory
    this->_brain = nullptr; // Set pointer to nullptr to avoid dangling pointer
}

void Dog::makeSound() const
{
    std::cout << "Dog:makeSound() called" << std::endl;
    std::cout << "Woof!" << std::endl;
}

std::string Dog::getIdea(int index) const
{
    return (_brain->getIdea(index));
}

void Dog::setIdea(int index, const std::string &idea)
{
    _brain->setIdea(index, idea);
}