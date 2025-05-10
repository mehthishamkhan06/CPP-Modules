#include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{

}

Zombie::~Zombie(){

    std::cout << this->_name << " R.I.P......!" << std::endl;
}

void    Zombie::announce(void){
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}