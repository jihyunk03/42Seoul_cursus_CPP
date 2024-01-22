#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Form;

class Bureaucrat
{
    private:
        const std::string   _name;
        int                 _grade;

    public:
        /* OCCF */
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& origin);
        Bureaucrat& operator=(const Bureaucrat& origin);
        ~Bureaucrat();

        /* member functions */
        const std::string&  getName(void) const;
        int                 getGrade(void) const;
        void                increaseGrade(void);
        void                decreaseGrade(void);
        void                signForm(Form& form);

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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& print);

#endif
