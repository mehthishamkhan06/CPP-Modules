#include <contact.hpp>

Contact::Contact(void){
    return ;
}

Contact::~Contact(void){
    return ;
}

int is_digit_str(std::string str)
{
    int i = 0;
    while (str[i]){
        if (!std::isdigit(str[i]))
            return (1);
        i++;
    }
    return (0);
}