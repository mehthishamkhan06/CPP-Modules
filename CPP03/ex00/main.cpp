#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- Object Construction Tests ---\n";
    ClapTrap defaultTrap;
    ClapTrap namedTrap("Zapper");
    ClapTrap copyTrap(namedTrap);
    ClapTrap assignedTrap;
    assignedTrap = namedTrap;


    std::cout << "\n--- Basic Attack Test ---\n";
    namedTrap.attack("Skag");

    std::cout << "\n--- Take Damage Test (HP should reduce by 3) ---\n";
    namedTrap.takeDamage(3);

    std::cout << "\n--- Repair Test (+2 HP) ---\n";
    namedTrap.beRepaired(2);

    std::cout << "\n--- Overkill Damage Test (reduce HP to 0) ---\n";
    namedTrap.takeDamage(15);
    std::cout << "\n--- Repair After Death (should fail) ---\n";
    namedTrap.beRepaired(5);

    std::cout << "\n--- Attack After Death (should fail) ---\n";
    namedTrap.attack("Bandit");

    std::cout << "\n--- Energy Depletion Test ---\n";
    ClapTrap lowEnergy("LowEnergy");
    for (int i = 0; i < 10; ++i) {
        lowEnergy.attack("Dummy");
    }
    std::cout << "[Attempting to attack with 0 energy]\n";
    lowEnergy.attack("Dummy");

    std::cout << "\n--- Repair With No Energy (should fail) ---\n";
    lowEnergy.beRepaired(1);

    std::cout << "\n--- Empty Target Attack (should handle gracefully) ---\n";
    defaultTrap.attack("");

    std::cout << "\n--- Taking Damage When Already at 0 HP (should not go negative) ---\n";
    namedTrap.takeDamage(1);

    return 0;
}
