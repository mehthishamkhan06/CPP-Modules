#include "ClapTrap.hpp"

int main() {
    ClapTrap c1("Zapper");
    ClapTrap c2(c1); // Test copy constructor
    ClapTrap c3;
    c3 = c1;         // Test assignment operator

    c1.attack("Skag");
    c1.takeDamage(3);
    c1.beRepaired(2);
    c1.takeDamage(15);
    c1.beRepaired(5);
    c1.attack("Bandit");


    return 0;
}
