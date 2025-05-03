#include "Contact.hpp"

Contact::Contact(){
    return ;
}

Contact::~Contact(){
    return ;
}


int ft_isstring_digit(std::string str){
    int i = 0;
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}

int is_phone_number_valid(std::string str){
    if (str.length() != 10 || !ft_isstring_digit(str))
        return 0;
    return 1;
}

void    Contact::setFirstName(void){
    std::string input_str;
    while (true)
    {
        std::cout << "Enter first name: ";
        if (!std::getline(std::cin, input_str))
            break ;
        if (!input_str.empty())
        {
            this->_first_name = input_str;
            break;
        }
        else
            std::cout << "Invalid first name. Please try again." << std::endl;
    }
}

std::string Contact::getFirstName(void) const{
    return this->_first_name;
}

void    Contact::setLastName(void){
    std::string input_str;
    while (true)
    {
        std::cout << "Enter last name: ";
        if (!std::getline(std::cin, input_str))
            break ;
        if (!input_str.empty())
        {
            this->_last_name = input_str;
            break;
        }
        else
            std::cout << "Invalid last name. Please try again." << std::endl;
    }
}

std::string Contact::getLastName(void) const
{
    return this->_last_name;
}

void    Contact::setNickName(void)
{
    std::string input_str;
    while (true)
    {
        std::cout << "Enter NickName: ";
        if (!std::getline(std::cin, input_str))
            break ;
        if (!input_str.empty())
        {
            this->_nickname = input_str;
            break;
        }
        else
            std::cout << "Invalid NickName. Please try again." << std::endl;
    }
}

std::string Contact::getNickName(void) const{
    return this->_nickname;
}

void    Contact::setPhoneNumber(void){
    std::string input_str;
    while (true)
    {
        std::cout << "Enter Phone Number: ";
        if (!std::getline(std::cin, input_str))
            break ;
        if (!input_str.empty() && is_phone_number_valid(input_str))
        {
            this->_phone_number = input_str;
            break;
        }
        else
            std::cout << "Invalid Phone Number. Please try again." << std::endl;
    }
}

std::string Contact::getPhoneNumber(void) const{
    return this->_phone_number;
}
void    Contact::setDarkestSecret(void){
    std::string input_str;
    while (true)
    {
        std::cout << "Enter Darkest Secret: ";
        if (!std::getline(std::cin, input_str))
            break ;
        if (!input_str.empty())
        {
            this->_darkest_secret = input_str;
            break;
        }
        else
            std::cout << "Invalid DarkestSecret. Please try again." << std::endl;
    }
}

std::string Contact::getDarkestSecret(void) const{
    return this->_darkest_secret;
}



void Contact::displayFull() const
{
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "|                 Contact                   |" << std::endl;
    std::cout << "First Name: " << this->_first_name << std::endl;
    std::cout << "Last Name: " << this->_last_name << std::endl;
    std::cout << "NickName: " << this->_nickname << std::endl;
    std::cout << "Phone Number: " << this->_phone_number << std::endl;
    std::cout << "Darkest Secret: " << this->_darkest_secret << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;
}