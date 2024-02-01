#include "./ScalarConverter.hpp"
#include <iomanip>
#include <cctype>
#include <limits>
#include <cmath>

/* static member variable */
double ScalarConverter::_dLiteral = 0;

/* static member functions */
void ScalarConverter::convert(const std::string& value)
{
    char *pos = NULL;

    // std::cout << std::fixed << std::setprecision(1);
    if (value.length() == 1)
        ScalarConverter::_dLiteral = static_cast<double>(value[0]);
    else
        ScalarConverter::_dLiteral = std::strtod(value.c_str(), &pos);
    ScalarConverter::_reSetprecision(value, pos);

    ScalarConverter::_printChar();
    ScalarConverter::_printInt();
    ScalarConverter::_printFloat();
    ScalarConverter::_printDouble();

    ScalarConverter::_dLiteral = 0;  // initialize to 0 (origin) for next convert
}

/* private & static member functions(only used in convert-func) */
void ScalarConverter::_reSetprecision(const std::string& value, char* pos)
{
    // if ()
}

void ScalarConverter::_printChar(void)
{
    char    convertChar = static_cast<char>(ScalarConverter::_dLiteral);

    std::cout << "char: ";
    if (convertChar != convertChar)
        std::cout << "impossible" << std::endl;
    else if (convertChar < std::numeric_limits<char>::min() || convertChar > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (std::isprint(convertChar) == 0)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << convertChar << std::endl;
}

void ScalarConverter::_printInt(void)
{
    int convertInt = static_cast<int>(ScalarConverter::_dLiteral);

    std::cout << "int: ";
    if (convertInt != convertInt)
        std::cout << "impossible" << std::endl;
    else if (convertInt < std::numeric_limits<int>::min() || convertInt > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << convertInt << std::endl;
}

void ScalarConverter::_printFloat(void)
{
    float convertFloat = static_cast<float>(ScalarConverter::_dLiteral);

    std::cout << "float: ";
    if (convertFloat != convertFloat)
        std::cout << "impossible" << std::endl;
    else if (std::isinf(convertFloat) == true)
    {
        if (std::signbit(convertFloat) == false)
            std::cout << "inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    }
    else if (std::isnan(convertFloat) == true)
        std::cout << "nanf" << std::endl;
    else
        std::cout << convertFloat << std::endl;
}

void ScalarConverter::_printDouble(void)
{
    float convertDouble = static_cast<float>(ScalarConverter::_dLiteral);

    std::cout << "double: ";
    if (convertDouble != convertDouble)
        std::cout << "impossible" << std::endl;
    else if (std::isinf(convertDouble) == true)
    {
        if (std::signbit(convertDouble) == false)
            std::cout << "inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
    }
    else if (std::isnan(convertDouble) == true)
        std::cout << "nanf" << std::endl;
    else
        std::cout << convertDouble << std::endl;
}
