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
    if (literal == "nanf" || literal == "+nanf" || literal == "-nanf" ||
        literal == "inff" || literal == "+inff" || literal == "-inff")
        return true;
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
    size_t i = 0;
    bool hasDecimal = false;
    if (literal == "nan" || literal == "+nan" || literal == "-nan" ||
        literal == "inf" || literal == "+inf" || literal == "-inf")
        return true;
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

void convertFromChar(char c)
{
    unsigned char uc = static_cast<unsigned char>(c);
    if (!std::isprint(uc))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(uc) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(uc) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(uc) << std::endl;
}


void convertFromInt(long i)
{
    unsigned char uc = static_cast<unsigned char>(i);
    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(uc))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << uc << "'" << std::endl;
    if (i < INT_MIN || i > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(i) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}


void convertFromFloat(float f)
{
    unsigned char uc = static_cast<unsigned char>(f);
    if (f < 0 || f > 127 || std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(uc))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << uc << "'" << std::endl;
    if (std::isnan(f) || std::isinf(f) || f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}
    
void convertFromDouble(double d)
{
    unsigned char uc =  static_cast<unsigned char>(d);
    if (d < 0 || d > 127 || std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(uc))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << uc << "'" << std::endl;
    if (std::isnan(d) || std::isinf(d) ||  d > static_cast<double>(INT_MAX) || d < static_cast<double>(INT_MIN))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    if (std::isnan(d) || std::isinf(d))
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    else if (d > static_cast<double>(FLT_MAX) || d < -static_cast<double>(FLT_MAX))
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    
}