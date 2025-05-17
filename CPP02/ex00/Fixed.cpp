#include "Fixed.hpp"


Fixed::Fixed(): _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &object)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = object; // copies the current instances of objects to this
}

Fixed& Fixed::operator=(Fixed const &right_value)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &right_value) // checks for self assigning
        this->_fixed = right_value.getRawBits(); // if its not same varible like a=a then it copies the rawbits to _fixed.
    return (*this);  // returns all instances
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits called" << std::endl;
    this->_fixed = raw;
}
int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed);
}

