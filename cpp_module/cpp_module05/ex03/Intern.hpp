#ifndef INTERN_HPP
# define INTERN_HPP

# include "./AForm.hpp"

class Intern
{
    private:
        /* member functions */
        AForm*  _makeShrubberyForm(const std::string& name);
        AForm*  _makeRobotoForm(const std::string& name);
        AForm*  _makePresidentialForm(const std::string& name);

    public:
        /* OCCF */
        Intern();
        Intern(const Intern& origin);
        Intern& operator=(const Intern& origin);
        ~Intern();

        /* member functions */
        AForm*  makeForm(const std::string& formName, const std::string& targetName);

        /* inner-class for exceptions */
        class AFormNameIsWrongException
            : public std::exception
        {
            public:
                virtual const char* what(void) const throw();
        };
};

#endif
