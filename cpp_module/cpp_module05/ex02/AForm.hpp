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
        virtual ~AForm();

        /* member functions */
        const std::string&  getName(void) const;
        void                setName(const std::string name);

        bool                getSigned(void) const;
        void                setSigned(bool isSigned);

        int                 getSignGrade(void) const;
        void                setSignGrade(int signGrade);

        int                 getExecuteGrade(void) const;
        void                setExecuteGrade(int executeGrade);

        void                beSigned(const Bureaucrat& sign);

        /* pure-virtual functions */
        virtual void        execute(const Bureaucrat& executor) const = 0;

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
