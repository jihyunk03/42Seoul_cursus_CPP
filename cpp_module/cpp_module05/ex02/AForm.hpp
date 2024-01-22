#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _executeGrade;

    public:
        /* OCCF */
        AForm();
        AForm(const std::string name, const int signGrade, const int executeGrade);
        AForm(const AForm& origin);
        AForm& operator=(const AForm& origin);
        ~AForm();

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
        class AFormAlreadySignedException
            : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& print);

#endif
