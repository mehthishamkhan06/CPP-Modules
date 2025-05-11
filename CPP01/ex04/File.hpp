#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

class File
{
    public:
        File();
        std::ifstream inputFile;

        void Search_And_Replace(char **argv);
        void display_error() const;
        ~File();

    private:
        std::string _tofind;
        std::string _toreplace;
        std::string _replacefile;
        std::ofstream _repfile;
        std::string _fileContent;

    void readFile();
    void writeFile(const std::string &newContent);
};
