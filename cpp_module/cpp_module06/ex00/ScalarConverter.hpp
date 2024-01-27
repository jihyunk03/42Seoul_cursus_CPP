#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
    private:
        /* OCCF */
        ScalarConverter();
        ScalarConverter(const ScalarConverter& origin);
        ScalarConverter& operator=(const ScalarConverter& origin);
        ~ScalarConverter();

        /* private member functions(only used in convert-func) */

    public:
        /* static member functions */
        static void convert(const std::string& value);
};

#endif
