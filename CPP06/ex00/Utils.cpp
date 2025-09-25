#include "ScalarConverter.hpp"
#include "Utils.hpp"

bool isCharLiteral(const std::string &literal)
{
    return literal.length() == 1 && std::isprint(literal[0]);
}

bool isIntLiteral(const std::string &literal)
{
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+')
        i++;
    for (; i < literal.length(); i++)
    {
        if (!std::isdigit(literal[i]))
            return (false);
    }
    return (true);
}

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
        {
            if (literal[i] == 'f' && i == literal.length() - 1 && hasDecimal)
                return (true);
            return (false);
        }
    }
    return (false);
}

bool isDoubleLiteral(const std::string &literal)
{

}

void convertFromChar(char c)
{
    if (!std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(static_cast<unsigned char>(c)) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(static_cast<unsigned char>(c)) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(static_cast<unsigned char>(c)) << std::endl;
}

void convertFromInt(int i)
{
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<unsigned char>(i) << "'" << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void convertFromFloat(float f)
{
    if (f < 0 || f > 127 || std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<unsigned char>(f) << "'" << std::endl;
    
    if (std::isnan(f) || std::isinf(f) || f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}