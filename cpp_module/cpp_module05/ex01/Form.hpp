#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _executeGrade;

    public:
        /* OCCF */
        Form();
        Form(const std::string name, const int signGrade, const int executeGrade);
        Form(const Form& origin);
        Form& operator=(const Form& origin);
        ~Form();

        /* member functions */
        const std::string&  getName(void) const;
        bool                getSigned(void) const;
        int                 getSignGrade(void) const;
        int                 getExecuteGrade(void) const;
        void                beSigned(const Bureaucrat& sign);

        /* inner-class for exceptions */
        class GradeTooHighException
            : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
        class GradeTooLowException
            : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
        class FormAlreadySignedException
            : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const Form& print);

#endif
