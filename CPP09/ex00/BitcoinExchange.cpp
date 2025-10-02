#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(std::string file_name)
{
    this->data_file = data_file;
    this->load_data(data_file);
    this->validate_file(file_name);

}

BitcoinExchange::BitcoinExchange(BitcoinExchange &copy){
    *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &copy){
    (void)copy;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){

}

void BitcoinExchange::load_data(std::string data_file)
{
    this->data_file = "data.csv";
    std::ifstream file(data_file.c_str());
    std::string line;
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data file.");
    while (std::getline(file, line))
    {
        size_t comma_pos = line.find(',');
        std::string date = line.substr(0, comma_pos);
        std::string value_str = line.substr(comma_pos + 1);
        double value = std::atof(value_str.c_str());
        // for (std::map<std::string, float>::iterator it = this->data_map.begin(); it != this->data_map.end(); it++)
        // {
        //     std::cout << it->first << " => " << it->second << std::endl;
        //     this->data_map[date] = value;
        // }
        std::cout << date << " | " << value << std::endl;
    }
    file.close();
}


void BitcoinExchange::validate_file(std::string file_name)
{
    std::ifstream file(file_name.c_str());
    std::string line;
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    while (std::getline(file, line))
    {
        std::cout << line << std::endl;
    }
    file.close();
}