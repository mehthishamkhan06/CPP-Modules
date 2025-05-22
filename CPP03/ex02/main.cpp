#include "FragTrap.hpp"
#include <iostream>

int main() {
    FragTrap frag("Fraggy");

    std::cout << std::endl;

    frag.attack("ClapMaster");
    frag.takeDamage(5);
    frag.beRepaired(3);

    std::cout << std::endl;

    frag.highFiveGuys(); // Should print a high five request

    std::cout << std::endl;

    // Testing when FragTrap is out of energy
    for (int i = 0; i < 10; ++i) {
        frag.attack("DummyTarget");
    }

    frag.highFiveGuys(); // Should now print that it can't do a high five (no energy left)

    std::cout << std::endl;

    // Testing when FragTrap is out of hit points
    frag.takeDamage(100);
    frag.highFiveGuys(); // Should now print that it can't do a high five (no HP)

    return 0;
}
