#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
	private :
		const std::string _name;
		bool _isSigned;
		const int _signGrade;
		const int _executeGrade;
		class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };

	public :
		Form();
		Form(const std::string &name, int signGrade, int executeGrade);
		Form(const Form &copy);
		Form &operator=(const Form &copy);
		~Form();
		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &copy);

#endif