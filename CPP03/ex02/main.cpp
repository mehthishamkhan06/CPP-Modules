#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "\n--- FragTrap Creation ---\n";
    FragTrap frag("Fraggy");

    std::cout << "\n--- Basic Attack, Damage, Repair ---\n";
    frag.attack("ClapMaster");
    frag.takeDamage(5);
    frag.beRepaired(3);

    std::cout << "\n--- High Five Test (Should Succeed) ---\n";
    frag.highFiveGuys();

    std::cout << "\n--- Draining Energy via Attacks ---\n";
    for (int i = 0; i < 100; ++i) {
        frag.attack("DummyTarget");
    }

    std::cout << "\n--- High Five With No Energy (Should Fail Gracefully) ---\n";
    frag.highFiveGuys();

    std::cout << "\n--- Taking Lethal Damage (HP = 0) ---\n";
    frag.takeDamage(100);

    std::cout << "\n--- High Five With No HP (Should Fail Gracefully) ---\n";
    frag.highFiveGuys();

    return 0;
}
