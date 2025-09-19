#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:
    std::string _target;

protected:
    void execute_forms(Bureaucrat const &executor) const;

public:
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &copy);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);
    virtual ~RobotomyRequestForm();

    const std::string &getTarget() const;
};
std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form);

#endif