#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &copy);
    Intern &operator=(const Intern &copy);
    ~Intern();

    AForm *makeForm(const std::string &formName, const std::string &target) const;
    AForm *createRobotomyRequestForm(const std::string &target) const;
    AForm *createShrubberyCreationForm(const std::string &target) const;
    AForm *createPresidentialPardonForm(const std::string &target) const;
    
    class FormNotFoundException : public std::exception {
    public:
        const char *what() const throw();
    };
};

#endif