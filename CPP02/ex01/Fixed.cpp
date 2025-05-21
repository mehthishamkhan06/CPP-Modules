#include "Fixed.hpp"

Fixed::Fixed(): _fixed(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int a)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixed = a << this->_bits; // convert integer to fixed-point representation
}

Fixed::Fixed(const float a)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixed = roundf(a * (1 << this->_bits)); // convert float to fixed-point representation
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

std::ostream& operator<<(std::ostream& os, const Fixed& f) {
    os << f.toFloat();  // output float representation of fixed-point value
    return os;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed);
}

void Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->_fixed = raw;
}

float Fixed::toFloat( void ) const
{
    return ((float)this->_fixed / (1 << this->_bits)); // convert fixed-point representation to float
}

int Fixed::toInt( void ) const
{
    return (this->_fixed >> this->_bits); // convert fixed-point representation to integer
}