#ifndef FILE_HPP
#define FILE_HPP

#include <iostream>
#include <fstream>
#include <string>

class File
{
public:
    File(const std::string &filename);
    ~File();

    void Search_And_Replace(argv);
    void display_error() const;

private:
    std::string _filename;
    std::ifstream _inputFile;
    std::ofstream _outputFile;
    std::string _fileContent;

    void readFile();
    void writeFile(const std::string &newContent);
};
