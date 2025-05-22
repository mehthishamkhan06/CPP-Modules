#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default_clap_name"), _name("Default") {

    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), _name(name)
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name) {
    std::cout << "DiamondTrap copy constructor called for " << this->_name << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    if (this != &other) {
        ClapTrap::operator=(other);
       this-> _name = other._name;
    }
    std::cout << "DiamondTrap assignment operator called for " << this->_name << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called for " << this->_name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() const {
    std::cout << "DiamondTrap name: " << this->_name << ", ClapTrap name: " << ClapTrap::_name << std::endl;
}