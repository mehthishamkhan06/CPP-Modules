#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 1);
        Bureaucrat alice("Alice", 150);

        ShrubberyCreationForm shrubberyForm("Home");
        RobotomyRequestForm robotomyForm("Robot");
        PresidentialPardonForm pardonForm("Criminal");

        std::cout << bob << std::endl;
        std::cout << alice << std::endl;

        std::cout << shrubberyForm << std::endl;
        std::cout << robotomyForm << std::endl;
        std::cout << pardonForm << std::endl;

        bob.signForm(shrubberyForm);
        bob.signForm(robotomyForm);
        bob.signForm(pardonForm);

        bob.executeForm(shrubberyForm);
        alice.executeForm(robotomyForm);
        bob.executeForm(pardonForm);

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}   