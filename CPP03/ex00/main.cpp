#include "ClapTrap.hpp"

int main() {
    ClapTrap defaultTrap;

    ClapTrap namedTrap("Zapper"); // Parameterized constructor test

    ClapTrap copyTrap(namedTrap); // Test copy constructor

    // Test assignment operator
    ClapTrap assignedTrap;
    assignedTrap = namedTrap;

    // Test attack (should succeed)
    namedTrap.attack("Skag");

    // Test takeDamage (normal case)
    namedTrap.takeDamage(3);

    // Test beRepaired (should succeed)
    namedTrap.beRepaired(2);

    // Test takeDamage (reduce HP to 0)
    namedTrap.takeDamage(15);

    // Test beRepaired when HP is 0 (should fail)
    namedTrap.beRepaired(5);

    // Test attack when HP is 0 (should fail)
    namedTrap.attack("Bandit");

    // Test attack with no energy points
    ClapTrap lowEnergy("LowEnergy");
    // Drain energy
    for (int i = 0; i < 10; ++i) lowEnergy.attack("Dummy");
    // Should fail due to no energy
    lowEnergy.attack("Dummy");

    // Test beRepaired with no energy points
    lowEnergy.beRepaired(1);

    // Test attack with empty target
    defaultTrap.attack("");

    // Test takeDamage when already at 0 HP
    namedTrap.takeDamage(1);

    return 0;
}
