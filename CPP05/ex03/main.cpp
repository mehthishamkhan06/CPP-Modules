#include "Intern.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern someRandomIntern;
    Bureaucrat bob("Bob", 42);

    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;

    try {
        form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        bob.signForm(*form1);
        bob.executeForm(*form1);

        form2 = someRandomIntern.makeForm("shrubbery creation", "Home");
        bob.signForm(*form2);
        bob.executeForm(*form2);

        form3 = someRandomIntern.makeForm("presidential pardon", "Marvin");
        bob.signForm(*form3);
        bob.executeForm(*form3);

        // Trying to create an unknown form
        AForm* form4 = someRandomIntern.makeForm("unknown form", "Nobody");
        delete form4; // This line won't be reached as the exception will be caught
    }
    catch (std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    // Cleaning up after alloction
    delete form1;
    delete form2;
    delete form3;

    return 0;
}
