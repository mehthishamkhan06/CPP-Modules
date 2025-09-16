#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <limits>

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
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        Bureaucrat &operator=(const Bureaucrat &copy);
        ~Bureaucrat();
        void gradeDecrement();
        void gradeIncrement();
        std::string getName() const;
        int getGrade() const;
        
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &copy);

#endif
