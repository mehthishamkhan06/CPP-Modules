#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
    Zombie* character = new Zombie(name);
    return (character);
}