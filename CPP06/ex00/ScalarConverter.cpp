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
        convertFromInt(std::stoi(literal));
    else if (isFloatLiteral(literal))
        convertFromFloat(std::stof(literal));
    else if (isDoubleLiteral(literal) || literal == "nan" || literal == "+inf" || literal == "-inf")
        convertFromDouble(std::stod(literal));
    
    else
        throw std::invalid_argument("Invalid input format"); //replace by custom ones later
}

// if (std::isnan(f) || std::isinf(f) || f > static_cast<float>(std::numeric_limits<int>::max()) || f < static_cast<float>(std::numeric_limits<int>::min()))
