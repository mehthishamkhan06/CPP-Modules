#include "Zombie.hpp"

Zombie* zombieHorde(int n, std::string name)
{
    Zombie* horde = new Zombie[n];
    for (int i = 0; i < n; i++)
    {
        horde[i].setName(name + " " + std::to_string(i + 1));
    }
    return (horde);
}