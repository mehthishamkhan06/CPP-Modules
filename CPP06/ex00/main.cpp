#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./scalar_converter <literal>" << std::endl;
        return (1);
    }
    try{
        std::string literal = argv[1];
        ScalarConverter::convert(literal);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return (0);
}