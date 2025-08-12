#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(120)
{
    std::cout << "Bureaucrat Default Constructor Called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor Called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
    std::cout << "Bureaucrat Name Constructor Called" << std::endl;
    try{
        if (_grade > 150)
            throw GradeTooLowException();
        else if (_grade < 1)
            throw GradeTooHighException();
        else
            this->_grade = grade;
    }
    catch (const std::exception &e){
        std::cerr << "Exception: " << e.what() << std::endl; 
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    std::cout << "Bureaucrat Copy Constructor called" << std::endl;
    *this = copy;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    std::cout << "Bureaucrat assignment operator called" << std::endl;
    if (this != &copy)
        this->_grade = copy._grade;
    return (*this);
}

void Bureaucrat::gradeDecrement()
{
    std::cout << "Bureaucrat Grade Decrement Called" << std::endl;
    try {
        if (this->_grade < 1)
            throw GradeTooHighException();
        else if (this->_grade > 150)
            throw GradeTooLowException();
        this->_grade++;
    } catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}
void Bureaucrat::gradeIncrement()
{
    std::cout << "Bureaucrat Grade Increment Called" << std::endl;
    try {
        if (this->_grade < 1)
            throw GradeTooHighException();
        else if (this->_grade > 150)
            throw GradeTooLowException();
        this->_grade--;
    }
    catch (const std::exception &e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}


const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade is too low!";
}

void Bureaucrat::executeForm(const AForm &form) const
{
    try {
        form.execute(*this);
        std::cout << this->_name << " executes " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << this->_name << " cannot execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &copy)
{
    out << copy.getName() << ", bureaucrat grade " << copy.getGrade();
    return out;
}

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signs " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << this->_name << " cannot sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
