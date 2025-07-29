#include "ClapTrap.hpp"


ClapTrap::ClapTrap() : _name("Default"), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "ClapTrap Default Constructor Called" << std::endl; 
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hitPoints(100), _energyPoints(50), _attackDamage(20)
{
    std::cout << "ClapTrap " << this->_name << " created sucessfully.!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "ClapTrap Copy Constructor Called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap Operator Overload" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor Called" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is out of hit points and cannot attack!" << std::endl;
        return;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is out of energy points and cannot attack!" << std::endl;
        return;
    }
    if (target.empty()) {
        std::cout << "ClapTrap " << this->_name << " has no target to attack!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is already out of hit points!" << std::endl;
        return;
    }

    this->_hitPoints -= amount;
    if (this->_hitPoints < 0) {
        this->_hitPoints = 0;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage! Hit points left: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is out of hit points and cannot be repaired!" << std::endl;
        return;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is out of energy points and cannot be repaired!" << std::endl;
        return;
    }
    this->_hitPoints += amount;
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " repairs itself for " << amount << " hit points! Hit points now: " << this->_hitPoints << std::endl;
}