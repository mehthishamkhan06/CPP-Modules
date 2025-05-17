#include "Harl.hpp"

int check_index(char *arg)
{
    int index = -1;
    std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for(int i = 0; i < 4; i++)
    {
        if (levels[i] == arg)
        {
            index = i;
            return (index);
        }
    }
    return (index);
}
void MrHarlComplain(char *args, Harl &Character)
{
    int index = 0;
    index = check_index(args);
    switch(index)
    {
        case 0:
            Character.complain("DEBUG");
            /*Fall Through*/
        case 1:
            Character.complain("INFO");
            /*Fall Through*/
        case 2:
            Character.complain("WARNING");
            /*Fall Through*/
        case 3:
            Character.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

    }
}
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