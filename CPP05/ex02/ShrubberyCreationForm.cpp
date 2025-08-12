#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() 
    : AForm("Shrubbery Creation Form", 145, 137), _target("Default") {
    std::cout << "ShrubberyCreationForm Default Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm Parameterized Constructor Called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) 
    : AForm(copy), _target(copy._target) {
    std::cout << "ShrubberyCreationForm Copy Constructor Called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    std::cout << "ShrubberyCreationForm Assignment Operator Called" << std::endl;
    if (this != &copy) {
        AForm::operator=(copy);
        this->_target = copy._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm Destructor Called" << std::endl;
}

const std::string &ShrubberyCreationForm::getTarget() const {
    return this->_target;
}

void ShrubberyCreationForm::execute_forms(Bureaucrat const &executor) const {
    (void)executor; // Suppress unused parameter warning
    std::ofstream file(this->_target + "_shrubbery");
    if (!file.is_open()) {
        throw std::ios_base::failure("Failed to open file for writing.");
    }

    file << "         _-_-_\n";
    file << "      /~~   ~~\\\n";
    file << "   /~~         ~~\\\n";
    file << "  {               }\n";
    file << "   \\  _-_-_-_-_  /\n";
    file << "     ~-_______-~\n";
    file << "       WELCOME\n";
    file << "         TO\n";
    file << "       CPP05\n";
    file << "     ***********\n";
    file << "    *************\n";
    file << "   ****************\n";
    file << "  ******************\n";
    file << " ********************\n";
    file << "        |||||\n";
    file << "        |||||\n";
    file << "        |||||\n";
    file << "        |||||\n";
    file << "        |||||\n";

    file.close();
}

std::ostream &operator<<(std::ostream &out, const ShrubberyCreationForm &form) {
    out << "ShrubberyCreationForm: " << form.getName() 
        << ", Target: " << form.getTarget() 
        << ", Is Signed: " << (form.getIsSigned() ? "Yes" : "No") 
        << ", Sign Grade: " << form.getSignGrade() 
        << ", Execute Grade: " << form.getExecuteGrade();
    return out;
}