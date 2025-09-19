#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() 
    : AForm("Robotomy Request Form", 72, 45), _target("Default") {
    std::cout << "RobotomyRequestForm Default Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request Form", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm Parameterized Constructor Called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) 
    : AForm(copy), _target(copy._target) {
    std::cout << "RobotomyRequestForm Copy Constructor Called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    std::cout << "RobotomyRequestForm Assignment Operator Called" << std::endl;
    if (this != &copy) {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm Destructor Called" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const {
    return (this->_target);
}

void RobotomyRequestForm::execute_forms(Bureaucrat const &executor) const {
    (void)executor;
    if(rand() % 2)
        std::cout << "Bzzzzzz... " << this->_target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Failed to robotomize " << this->_target << "." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const RobotomyRequestForm &form) {
    out << "RobotomyRequestForm: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No") 
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Execute Grade: " << form.getExecuteGrade();
    return (out);
}