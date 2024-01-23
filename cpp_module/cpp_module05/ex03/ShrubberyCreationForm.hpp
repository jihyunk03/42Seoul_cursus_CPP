#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "./AForm.hpp"

# define SC_SIGN    145
# define SC_EXCE    137
# define ASCII_TREE "        _    .  ,   .           .\n\
    *  / \\_ *  / \\_      _  *        *   /\\\'__        *\n\
      /    \\  /    \\,   ((        .    _/  /  \\  *\'.\n\
 .   /\\/\\  /\\/ :\' __ \\_  `          _^/  ^/    `--.\n\
    /    \\/  \\  _/  \\-\'\\      *    /.\' ^_   \\_   .\'\\  *\n\
  /\\  .-   `. \\/     \\ /==~=-=~=-=-;.  _/ \\ -. `_/   \\\n\
 /  `-.__ ^   / .-\'.--\\ =-=~_=-=~=^/  _ `--./ .-\'  `-\n\
/kjh     `.  / /       `.~-^=-=~=^=.-\'      \'-._ `._"

class ShrubberyCreationForm
    : public AForm
{
    public:
        /* OCCF */
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string& name);
        ShrubberyCreationForm(const ShrubberyCreationForm& origin);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& origin);
        ~ShrubberyCreationForm();

        /* pure-virtual functions(override) */
        virtual void    execute(const Bureaucrat& executor) const;
};

#endif
