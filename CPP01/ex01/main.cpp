#include "Zombie.hpp"

int main(void)
{
    int no_of_zombies = 5;

    Zombie *zombies = zombieHorde(no_of_zombies, "Zombie");
    delete[] zombies;
    return (0);
}