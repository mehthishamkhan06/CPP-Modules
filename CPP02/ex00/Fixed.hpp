    #ifndef FIXED_HPP
    # define FIXED_HPP

    #include <iostream>
    #include <string>

    class Fixed{
        private:
            int _fixed;
            static const int _bits = 8; //donno why are we using this

        public:
            Fixed();
            Fixed(const Fixed &object);
            Fixed &operator=(Fixed const &right_value);
            ~Fixed();
            int getRawBits( void ) const;
            void setRawBits( int const raw );

    };

    #endif