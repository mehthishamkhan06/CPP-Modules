#include "Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie zombie_name = Zombie(name);
    zombie_name.announce();
}