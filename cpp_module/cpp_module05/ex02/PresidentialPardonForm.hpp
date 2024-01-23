#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "./AForm.hpp"

# define PP_SIGN    25
# define PP_EXEC    5

class PresidentialPardonForm
    : public AForm
{
    public:
        /* OCCF */
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string& name);
        PresidentialPardonForm(const PresidentialPardonForm& origin);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& origin);
        ~PresidentialPardonForm();

        /* pure-virtual functions(override) */
        virtual void    execute(const Bureaucrat& executor) const;
};

#endif
