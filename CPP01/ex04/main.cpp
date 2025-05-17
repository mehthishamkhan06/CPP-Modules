#include "File.hpp"

int main(int argc, char *argv[])
{
    File file;
    if (argc == 4)
    {
        if (file.openFile(argv[1]))
            file.Search_And_Replace(argv);
        else 
            std::cerr << "Error: Cannot open input or output file." << std::endl;
    }
    else
        file.display_error();
    return (0);
}