#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP


#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm {
private:
    std::string _target;
protected:
    void execute_forms(Bureaucrat const &executor) const;

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &copy);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);
    virtual ~ShrubberyCreationForm();

    const std::string &getTarget() const;
};
std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form);

# endif

