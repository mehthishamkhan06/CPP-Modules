#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie{
    private:
            std::string _name;
    public:
        Zombie(std::string name);
        Zombie(void);
        ~Zombie();

        void announce(void);
        void setName(std::string name);
};

Zombie* zombieHorde(int n, std::string name);

#endif