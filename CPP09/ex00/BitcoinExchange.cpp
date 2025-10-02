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
bool is_numeric(const std::string &s)
{
    for (size_t i = 0; i < s.size(); ++i)
    {
        if (!std::isdigit(s[i]))
            return false;
    }
    return true;
}

int validate_day(int y, int m, int d)
{
    bool is_leap = false;
    int max_days = 0;
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0))
        is_leap = true;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        max_days = 31;
    else if (m == 4 || m == 6 || m == 9 || m == 11)
        max_days = 30;
    else if (m == 2)
    {
        if (is_leap == true)
            max_days = 29;
        else
            max_days = 28;
    }
    else
        return (1);
    if (d < 1 || d > max_days)
        return (1);
    return (0);
}
int validate_Y_M_D(std::string year, std::string month, std::string day)
{
    if (!is_numeric(year) || !is_numeric(month) || !is_numeric(day))
        return (1);
    int y = atoi(year.c_str());
    int m = atoi(month.c_str());
    int d = atoi(day.c_str());
    if (m < 0 || m > 12)
        return (1);
    if (validate_day(y, m, d))
        return (1);
    return (0);
}

int BitcoinExchange::validate_date(std::string date)
{
    if ((date.size() == 10 && date[4] == '-' && date[7] == '-')){
        std::string year = date.substr(0, 4);
        std::string month = date.substr(5,2);
        std::string day = date.substr(8, 2);
        if (validate_Y_M_D(year, month, day))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            return (1);
        }
        return(0);
    }
    else
    {
        std::cerr << "Error: bad input => " << date << std::endl;
        return (1);
    }
    return (0);
}

void BitcoinExchange::trim_date_and_value(std::string *date, std::string *value)
{
    date->erase(0, date->find_first_not_of(' '));
    date->erase(date->find_last_not_of(' ') + 1);
    value->erase(0, value->find_first_not_of(' '));
    value->erase(value->find_last_not_of(' ') + 1);
}


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
            continue;
        }
        std::string date = line.substr(0, pipe_pos);
        std::string value_str = line.substr(pipe_pos + 1);
        this->trim_date_and_value(&date, &value_str);
        if (this->validate_date(date))
            continue;;
        std::cout << line << std::endl;
    }
    file.close();
}   
