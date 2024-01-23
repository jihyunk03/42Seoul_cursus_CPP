#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "./AForm.hpp"

# define RR_SIGN    72
# define RR_EXEC    45

class RobotomyRequestForm
    : public AForm
{
    public:
        /* OCCF */
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string& name);
        RobotomyRequestForm(const RobotomyRequestForm& origin);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& origin);
        ~RobotomyRequestForm();

        /* pure-virtual functions(override) */
        virtual void    execute(const Bureaucrat& executor) const;
};

#endif
