#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Default Constructor Called" << std::endl;
}

Intern::Intern(const Intern &copy) {
    std::cout << "Intern Copy Constructor Called" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy) {
    std::cout << "Intern Assignment Operator Called" << std::endl;
    (void)copy;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern Destructor Called" << std::endl;
}

AForm *Intern::createRobotomyRequestForm(const std::string &target) const {
    return new RobotomyRequestForm(target);
}

AForm *Intern::createShrubberyCreationForm(const std::string &target) const {
    return new ShrubberyCreationForm(target);
}
AForm *Intern::createPresidentialPardonForm(const std::string &target) const {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const {
    const std::string formNames[] = {
        "robotomy request",
        "shrubbery creation",
        "presidential pardon"
    };

    AForm *(Intern::*forms[3])(const std::string &) const = {
        &Intern::createRobotomyRequestForm,
        &Intern::createShrubberyCreationForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (this->*forms[i])(target);
        }   
    }
    std::cout << "Intern could not create form: " << formName << std::endl;
    throw FormNotFoundException();
}


const char *Intern::FormNotFoundException::what() const throw() {
    return "Form not found";
}