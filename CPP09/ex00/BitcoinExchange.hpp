#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <map>
#include <cstdlib>


class BitcoinExchange{
    private:
        void validate_file(std::string file_name);
        std::string data_file;
        void load_data(std::string data_file);
        std::map<std::string, float> data_map;
    
    public:
        BitcoinExchange();
        BitcoinExchange(std::string file_name);
        BitcoinExchange(BitcoinExchange &copy);
        BitcoinExchange &operator=(BitcoinExchange &copy);
        ~BitcoinExchange();
};

#endif
