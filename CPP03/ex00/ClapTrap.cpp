#include "Claptrap.hpp"


ClapTrap::ClapTrap(){
    std::cout << "Default Constructor Called" << std::endl; 
}

ClapTrap::ClapTrap(const std::string& name): _name(name)
{
    std::cout << "ClapTrap " << this->_name << "created sucessfully.!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    *this = other;
    std::cout << "Copy Constructor Called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    std::cout << "Operator Overload" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor Called" << std::endl;
}


void attack(const std::string& target)
{
    
}
