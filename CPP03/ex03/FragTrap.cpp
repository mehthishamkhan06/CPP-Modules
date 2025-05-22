#include "FragTrap.hpp"


FragTrap::FragTrap() : ClapTrap(), _highFives(false)
{
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name), _highFives(false)
{
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other), _highFives(other._highFives)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this != &other) {
        ClapTrap::operator=(other);
        _highFives = other._highFives;
    }
    std::cout << "FragTrap assignment operator called" << std::endl;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFiveGuys() const
{
    if (this->_hitPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " is out of hit points and cannot high five!" << std::endl;
        return;
    }
    else if (this->_energyPoints <= 0) {
        std::cout << "FragTrap " << this->_name << " is out of energy points and cannot high five!" << std::endl;
        return;
    }
    std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}