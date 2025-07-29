#include "DiamondTrap.hpp"

int main() {
    std::cout << "\n--- Creating DiamondTrap A ---\n";
    DiamondTrap dtA("Aegis");

    std::cout << "\n--- Testing Attack ---\n";
    dtA.attack("TargetDummy");

    std::cout << "\n--- Testing Take Damage (-30 HP) ---\n";
    dtA.takeDamage(30);

    std::cout << "\n--- Testing Repair (+20 HP) ---\n";
    dtA.beRepaired(20);

    std::cout << "\n--- Testing Identity (whoAmI) ---\n";
    dtA.whoAmI();

    std::cout << "\n--- Creating DiamondTrap B (copy of A) ---\n";
    DiamondTrap dtB(dtA); 

    std::cout << "\n--- Assigning DiamondTrap C to A ---\n";
    DiamondTrap dtC;
    dtC = dtA;

    std::cout << "\n--- whoAmI on B and C ---\n";
    dtB.whoAmI();
    dtC.whoAmI();

    std::cout << "\n--- End of main (Destructors Incoming) ---\n";
    return 0;
}
