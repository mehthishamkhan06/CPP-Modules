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
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy._name), _grade(copy._grade)
{
    std::cout << "Bureaucrat Copy Constructor called" << std::endl;
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
    if (this->_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
}
void Bureaucrat::gradeIncrement()
{
    std::cout << "Bureaucrat Grade Increment Called" << std::endl;
    if (this->_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
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

std::ostream& operator<<(std::ostream &out, const Bureaucrat &copy)
{
    out << copy.getName() << ", bureaucrat grade " << copy.getGrade();
    return out;
}

