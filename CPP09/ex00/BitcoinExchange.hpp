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
        void calculate(double value, std::string date);
        int validate_date(std::string date);
        double validate_value(std::string value_str);
        void trim_date_and_value(std::string *date, std::string *value);
        std::string data_file;
        void load_data(std::string data_file);
        std::map<std::string, double> data_map;
    
    public:
        BitcoinExchange();
        BitcoinExchange(std::string file_name);
        BitcoinExchange(BitcoinExchange &copy);
        BitcoinExchange &operator=(BitcoinExchange &copy);
        ~BitcoinExchange();
};

#endif
