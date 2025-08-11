#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class AForm {
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
		AForm();
		AForm(const std::string &name, int signGrade, int executeGrade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy);
		~AForm();
		const std::string &getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecuteGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);
        virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream& operator<<(std::ostream &out, const AForm &copy);

#endif