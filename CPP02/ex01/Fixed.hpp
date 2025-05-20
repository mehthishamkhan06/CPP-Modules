#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>

class Fixed{
    private:
        int _fixed_pointer;
        static const int _bits = 8;

    public:
        float toFloat( void ) const;
        int toInt( void ) const;
}