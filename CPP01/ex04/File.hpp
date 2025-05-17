#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

class File
{
    public:
        File();
        
        void Search_And_Replace(char **argv);
        void display_error() const;
        bool openFile(const std::string &filename);
        ~File();
        
        private:
        std::ifstream _inputFile;
        std::string _tofind;
        std::string _toreplace;
        std::string _replacefile;
        std::ofstream _repfile;
        std::string _fileContentline;

};

#endif