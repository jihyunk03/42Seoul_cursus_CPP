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

        /* private member variable */
        static double   _dLiteral;

        /* private member functions(only used in convert-func) */
        static void _reSetprecision(const std::string& value, char* pos);
        static void _printChar(void);
        static void _printInt(void);
        static void _printFloat(void);
        static void _printDouble(void);

    public:
        /* static member functions */
        static void convert(const std::string& value);
};

#endif
