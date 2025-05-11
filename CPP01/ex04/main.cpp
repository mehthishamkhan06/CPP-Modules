#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        Search_And_Replace(argv);
    }
    else
        display_error();
}