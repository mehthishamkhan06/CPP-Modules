#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){

}

BitcoinExchange::BitcoinExchange(std::string file_name)
{
    this->data_file = "data.csv";
    this->load_data(this->data_file);
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
    std::ifstream file(data_file.c_str());
    std::string line;
    if (!file.is_open())
        throw std::runtime_error("Error: could not open data file.");
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t comma_pos = line.find(',');
        std::string date = line.substr(0, comma_pos);
        std::string value_str = line.substr(comma_pos + 1);
        double value = std::atof(value_str.c_str());
        this->data_map[date] = value;
    }
    file.close();
}


void BitcoinExchange::trim_date_and_value(std::string *date, std::string *value)
{
    date->erase(0, date->find_first_not_of(' '));
    date->erase(date->find_last_not_of(' ') + 1);
    value->erase(0, value->find_first_not_of(' '));
    value->erase(value->find_last_not_of(' ') + 1);
}

// void BitcoinExchange::validate_date(std::string date)
// {


// }

void BitcoinExchange::validate_file(std::string file_name)
{
    std::ifstream file(file_name.c_str());
    std::string line;
    if (!file.is_open())
    throw std::runtime_error("Error: could not open file.");
    std::getline(file, line);
    while (std::getline(file, line))
    {
        size_t pipe_pos = 0;
        pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            std::getline(file, line);
        }
        std::string date = line.substr(0, pipe_pos);
        std::string value_str = line.substr(pipe_pos + 1);
        this->trim_date_and_value(&date, &value_str);
        // this->validate_date(date);
        std::cout << line << std::endl;
    }
    file.close();
}
