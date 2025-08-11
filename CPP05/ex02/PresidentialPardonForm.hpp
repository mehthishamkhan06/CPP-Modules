#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string _target;

protected:
    void execute_forms();

public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &copy);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);
    virtual ~PresidentialPardonForm();

    const std::string &getTarget() const;
};
std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form);

#endif