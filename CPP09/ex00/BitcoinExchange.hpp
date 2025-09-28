#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>

class BitcoinExchange{
    public:
        BitcoinExchange();
        BitcoinExchange(BitcoinExchange &copy);
        BitcoinExchange &operator=(BitcoinExchange &copy);
        ~BitcoinExchange();
}
