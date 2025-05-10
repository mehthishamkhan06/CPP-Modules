#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name)
{
    this->_weaponB = NULL;
}
HumanB::~HumanB()
{
}

void setWeapon(Weapon& weapon_B)
{
    this->_weaponB = &weapon_B;
}

void HumanB::attack(void)
{
    if (this->_weaponB)
        std::cout << this->_name << " attacks with their " << this->_weaponB->getType() << std::endl;
    else
        std::cout << this->_name << " has no weapon to attack" << std::endl;
}