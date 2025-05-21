#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed{
    private:
        int _fixed;
        static const int _bits = 8;

    public:
        //Contructors
        Fixed();
        Fixed(const int a);
        Fixed(const float a);
        //Copy constructor
        Fixed(const Fixed &object);
        //Destructor
        ~Fixed();
        //Copy assignment operator
        Fixed& operator=(Fixed const &right_value);
        float toFloat( void ) const;
        int toInt( void ) const;

        //from previous exrcise
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif