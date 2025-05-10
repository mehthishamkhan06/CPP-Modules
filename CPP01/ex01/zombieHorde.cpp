#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
    if (n <= 0)
    {
        std::cout << "Enter a number greater than or equal to 0" << std::endl;
        return (NULL);
    }
    Zombie* horde = new Zombie[n];
    for (int i = 0; i < n; i++)
    {
        horde[i].setName(name);
        horde[i].announce();
    }
    return (horde);
}