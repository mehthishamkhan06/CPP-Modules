#include "Form.hpp"

Form::Form(): _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
    std::cout << "Form Default Constructor Called" << std::endl;
}

Form::Form(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    std::cout << "Form Parameterized Constructor Called" << std::endl;
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy)
    : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {
    std::cout << "Form Copy Constructor Called" << std::endl;
}

Form &Form::operator=(const Form &copy) {
    std::cout << "Form Assignment Operator Called" << std::endl;
    if (this != &copy) {
        this->_isSigned = copy._isSigned;
    }
    return (*this);
}

Form::~Form() {
    std::cout << "Form Destructor Called" << std::endl;
}

const std::string &Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecuteGrade() const {
    return this->_executeGrade;
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_isSigned) {
        std::cout << "Form " << this->_name << " is already signed." << std::endl;
        return;
    }
    else if (bureaucrat.getGrade() > this->_signGrade) {
        throw GradeTooLowException();
    }
    else 
        this->_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char*Form::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream &out, const Form &form) {
    out << "Form Name: " << form.getName() 
        << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") 
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Execute Grade: " << form.getExecuteGrade();
    return (out);
}

