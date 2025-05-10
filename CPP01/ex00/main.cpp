#include "Zombie.hpp"

int main(void)
{
    Zombie *zombie_name = newZombie("Zombie 1");
    zombie_name->announce();
    delete zombie_name;
    randomChump("Zombie 2");
}