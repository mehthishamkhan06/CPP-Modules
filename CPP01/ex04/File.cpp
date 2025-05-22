#include "File.hpp"

File::File(){

}

File::~File(){
    if (_inputFile.is_open())
        _inputFile.close();
    if (_repfile.is_open())
        _repfile.close();
}

bool File::openFile(const std::string &filename){
    _inputFile.open(filename.c_str());
    if (!_inputFile.is_open())
        return (false);
    this-> _replacefile = filename + ".replace";
    this-> _repfile.open(_replacefile.c_str());
    return (_repfile.is_open());
}

void File::Search_And_Replace(char **argv){
    this-> _tofind = argv[2];
    this-> _toreplace = argv[3];
    if (this->_tofind.empty()) {
    std::cerr << "Error: String to find cannot be empty." << std::endl;
    return;
    }

    while ( std::getline(_inputFile, _fileContentline))
    {
        std::string result;
        size_t start = 0;
        size_t pos = 0;
        while((pos = _fileContentline.find(_tofind, start)) != std::string::npos)
        {
            result += _fileContentline.substr(start, pos - start);
            result += _toreplace;
            start = pos + _tofind.length();
        }
        result += _fileContentline.substr(start);
        _repfile << result << std::endl;
    }
    
}

void File::display_error() const{
    std::cerr << "Error: Invalid arguments. Usage: ./replace <filename> <s1> <s2>" << std::endl;
}