#include "File.hpp"


File::File()
{

}

File::~File()
{
    if (inputFile.is_open())
        inputFile.close();
    // if (_outpu.is_open())
    //     _outputFile.close();
}

void File::Search_And_Replace(File::inputFile, char **argv)
{
    this-> _tofind = argv[2];
    this-> _toreplace = argv[3];
    this-> _replacefile = argv[1] + ".replace";
    File::_repfile(_replacefile.c_str());
    
}
void File::display_error() const
{
    std::cerr << "Error: Invalid arguments. Usage: ./replace <filename> <s1> <s2>" << std::endl;
}