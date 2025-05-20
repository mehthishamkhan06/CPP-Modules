#include "Fixed.hpp"

Fixed::Fixed(): _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float a)
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object;
}

Fixed::~Fixed()
{
    std::cout << "Default destructor called" << std::endl;
}

Fixed& Fixed::operator=(Fixed const &right_value)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &right_value) // checks for self assigning
        this->_fixed = right_value.getRawBits(); // if its not same varible like a=a then it copies the rawbits to _fixed.
    return (*this);  // returns all instances
}