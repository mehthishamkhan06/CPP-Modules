#include <iostream>
#include <string>

int main(int argc, char *argv[])
{

    if (argc == 4)
    {
        File::inputFile.open(argv[1]);
        if (inputFile)
        {
            if (inputFile.is_open())
                Search_And_Replace(inputFile, argv);
            else
                std::cerr << "File Not Opened" << std::endl;
        }
        else 
            std::cerr << "File Doesn't Exist" << std::endl;
    }
    else
        display_error();
    return (0);
}