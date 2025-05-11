#include "File.hpp"


File::File(const std::string &filename) : _filename(filename)
{
    readFile();
}

File::~File()
{
    if (_inputFile.is_open())
        _inputFile.close();
    if (_outputFile.is_open())
        _outputFile.close();
}

void File::S
void File::display_error() const
{
    std::cerr << "Error: Invalid arguments. Usage: ./replace <filename> <s1> <s2>" << std::endl;
}