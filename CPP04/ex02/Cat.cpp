#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
    this->_type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->_brain = new Brain(*copy._brain);
    this->_type = copy._type;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &copy)
    {
        Animal::operator=(copy); // Call base class assignment operator
        delete this->_brain; // Free existing brain
        this->_brain = new Brain(*copy._brain); // Create a new brain
        this->_type = copy._type;
    }
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->_brain; // Free the brain memory
    this->_brain = nullptr; // Set pointer to nullptr to avoid dangling pointer
}

void Cat::makeSound() const
{
    std::cout << "Cat:makeSound() called" << std::endl;
    std::cout << "Meow!" << std::endl;
}

std::string Cat::getIdea(int index) const
{
    return (_brain->getIdea(index));
}

void Cat::setIdea(int index, const std::string &idea)
{
    _brain->setIdea(index, idea);
}