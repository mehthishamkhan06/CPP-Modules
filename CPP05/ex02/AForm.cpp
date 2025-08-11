#include "AAForm.hpp"

AForm::AForm(): _name("Default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
    std::cout << "AForm Default Constructor Called" << std::endl;
}

AForm::AForm(const std::string &name, int signGrade, int executeGrade)
    : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
    std::cout << "AForm Parameterized Constructor Called" << std::endl;
    try {
        if (signGrade < 1 || executeGrade < 1)
            throw GradeTooHighException();
        if (signGrade > 150 || executeGrade > 150)
            throw GradeTooLowException();
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

    AForm::AForm(const AForm &copy)
        : _name(copy._name), _isSigned(copy._isSigned), _signGrade(copy._signGrade), _executeGrade(copy._executeGrade) {
        std::cout << "AForm Copy Constructor Called" << std::endl;
    }

AForm &AForm::operator=(const AForm &copy) {
    std::cout << "AForm Assignment Operator Called" << std::endl;
    if (this != &copy) {
        this->_isSigned = copy._isSigned;
    }
    return (*this);
}

AForm::~AForm() {
    std::cout << "AForm Destructor Called" << std::endl;
}

const std::string &AForm::getName() const {
    return this->_name;
}

bool AForm::getIsSigned() const {
    return this->_isSigned;
}

int AForm::getSignGrade() const {
    return this->_signGrade;
}

int AForm::getExecuteGrade() const {
    return this->_executeGrade;
}
void AForm::beSigned(const Bureaucrat &bureaucrat) {
    if (this->_isSigned) {
        std::cout << "AForm " << this->_name << " is already signed." << std::endl;
        return;
    }
    else if (bureaucrat.getGrade() > this->_signGrade) {
        throw GradeTooLowException();
    }
    else 
        this->_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char*AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream &out, const AForm &AForm) {
    out << "AForm Name: " << AForm.getName() 
        << ", Signed: " << (AForm.getIsSigned() ? "Yes" : "No") 
        << ", Sign Grade: " << AForm.getSignGrade() 
        << ", Execute Grade: " << AForm.getExecuteGrade();
    return (out);
}

