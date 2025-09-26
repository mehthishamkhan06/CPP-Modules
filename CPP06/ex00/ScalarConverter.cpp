#include "ScalarConverter.hpp"
#include "Utils.hpp"

ScalarConverter::ScalarConverter(){
    
}

ScalarConverter::ScalarConverter(const ScalarConverter& other){ 
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(std::string literal)
{
    if (literal.empty())
        throw std::invalid_argument("Empty input is not allowed"); //replace by custom ones late
    if (isCharLiteral(literal))
        convertFromChar(literal[0]);
    else if (isIntLiteral(literal))
        convertFromInt(static_cast<int>(strtol(literal.c_str(),0, 10)));
    else if (isFloatLiteral(literal))
        convertFromFloat(strtof(literal.c_str(), 0));
    else if (isDoubleLiteral(literal))
        convertFromDouble(strtod(literal.c_str(), 0));
    else
        throw std::invalid_argument("Invalid input format"); //replace by custom ones later
}

