#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "Creating DiamondTrap A...\n";
    DiamondTrap dtA("Aegis");

    std::cout << "\nTesting attack...\n";
    dtA.attack("TargetDummy");

    std::cout << "\nTesting takeDamage...\n";
    dtA.takeDamage(30);

    std::cout << "\nTesting beRepaired...\n";
    dtA.beRepaired(20);

    std::cout << "\nTesting whoAmI...\n";
    dtA.whoAmI();

    std::cout << "\nCreating DiamondTrap B (copy of A)...\n";
    DiamondTrap dtB(dtA);  // Copy constructor

    std::cout << "\nAssigning DiamondTrap C to A...\n";
    DiamondTrap dtC;
    dtC = dtA;  // Copy assignment operator

    std::cout << "\nCalling whoAmI on B and C...\n";
    dtB.whoAmI();
    dtC.whoAmI();

    std::cout << "\nEnd of main, destructors will be called...\n";
    return 0;
}
