#include <iostream>
#include <string>

bool isFloatLiteral(const std::string &literal)
{
    size_t i = 0;
    bool hasDecimal = false;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (literal[i] == '.')
        {
            if (hasDecimal)
                return (false);
            hasDecimal = true;
        }
        else if (!std::isdigit(literal[i]))
            return (false);
    }
    return (hasDecimal);
}

int main(int ac, char *argv[])
{
    bool a = (isFloatLiteral(argv[1]));
    std::cout << a << std::endl; 
    return 0;
}