#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guardMode(false)
{
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name), _guardMode(false)
{
    std::cout << "ScavTrap constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other), _guardMode(other._guardMode)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        _guardMode = other._guardMode;
    }
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << "ScavTrap " << this->_name << " is out of energy points and cannot attack!" << std::endl;
        return;
    }
    if (target.empty()) {
        std::cout << "ScavTrap " << this->_name << " has no target to attack!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}


void ScavTrap::guardGate()
{
    if (this->_guardMode) {
        std::cout << "ScavTrap " << this->_name << " is already in Gate keeper mode!" << std::endl;
    } else {
        this->_guardMode = true;
        std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
    }
}