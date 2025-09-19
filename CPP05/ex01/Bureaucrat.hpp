#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>
#include "Form.hpp"

class Form;
class Bureaucrat {
    private:
        const std::string _name;
        int _grade;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

    public:
        //Canonical form
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        //Increament & Decrement
        void gradeDecrement();
        void gradeIncrement();
        //Getters
        std::string getName() const;
        int getGrade() const;
        //Sign form
        void signForm(Form &form);
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat &copy);

#endif
