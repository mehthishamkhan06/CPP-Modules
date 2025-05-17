#include "Harl.hpp"

int main(int argc, char *argv[])
{
    Harl Character;
    if (argc == 2)
    {
        MrHarlComplain(argv[1], Character);

    }
    else
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}