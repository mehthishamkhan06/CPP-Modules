#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() 
    : AForm("Presidential Pardon Form", 25, 5), _target("Default") {
    std::cout << "PresidentialPardonForm Default Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {
    std::cout << "PresidentialPardonForm Parameterized Constructor Called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) 
    : AForm(copy), _target(copy._target) {
    std::cout << "PresidentialPardonForm Copy Constructor Called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    std::cout << "PresidentialPardonForm Assignment Operator Called" << std::endl;
    if (this != &copy) {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm Destructor Called" << std::endl;
}

const std::string &PresidentialPardonForm::getTarget() const {
    return this->_target;
}

void PresidentialPardonForm::execute_forms(Bureaucrat const &executor) const{
    (void)executor; // Suppress unused parameter warning
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const PresidentialPardonForm &form) {
    out << "PresidentialPardonForm: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No") 
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}