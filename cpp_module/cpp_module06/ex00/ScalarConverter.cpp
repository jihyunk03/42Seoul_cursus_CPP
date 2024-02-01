#include "./ScalarConverter.hpp"
#include <iomanip>
#include <cctype>
#include <limits>
#include <cmath>

/* for print */
static void     _printChar(double dLiteral, bool errFlag);
static void     _printInt(double dLiteral, bool errFlag);
static void     _printFloat(double dLiteral, bool errFlag, const std::string& value, bool isFloat);
static void     _printDouble(double dLiteral, bool errFlag);
/* for check */
static bool     _isNan(const std::string& value);
static size_t   _setprecision(const std::string& value, bool isFloat);
static bool     _checkValid(char* pos, bool& isFloat);

/* static member functions */
void ScalarConverter::convert(const std::string& value)
{
    double  dLiteral;
    char    *pos = NULL;
    bool    errFlag = false;
    bool    isFloat = false;

    if (value.length() == 1)
        dLiteral = static_cast<double>(value[0]);
    else
    {
        if (_isNan(value) == true)
            return ;
        dLiteral = std::strtod(value.c_str(), &pos);
        if (errno == ERANGE)
            errFlag = true;
        if (_checkValid(pos, isFloat) == false)
            errFlag = true;
    }

    _printChar(dLiteral, errFlag);
    _printInt(dLiteral, errFlag);
    _printFloat(dLiteral, errFlag, value, isFloat);
    _printDouble(dLiteral, errFlag);
}

/* static functions only for ScalarConverter::convert() */
/* for print */
static void _printChar(double dLiteral, bool errFlag)
{
    char    convertChar = static_cast<char>(dLiteral);

    std::cout << "char: ";
    if (errFlag == true)
        std::cout << "impossible" << std::endl;
    else if (dLiteral < std::numeric_limits<char>::min() || dLiteral > std::numeric_limits<char>::max())
        std::cout << "impossible" << std::endl;
    else if (std::isprint(convertChar) == 0)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "\'" << convertChar << "\'" << std::endl;
}

static void _printInt(double dLiteral, bool errFlag)
{
    int convertInt = static_cast<int>(dLiteral);

    std::cout << "int: ";
    if (errFlag == true)
        std::cout << "impossible" << std::endl;
    else if (dLiteral < std::numeric_limits<int>::min() || dLiteral > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << convertInt << std::endl;
}

static void _printFloat(double dLiteral, bool errFlag, const std::string& value, bool isFloat)
{
    float convertFloat = static_cast<float>(dLiteral);

    std::cout << "float: ";
    if (errFlag == true || convertFloat != convertFloat)
        std::cout << "impossible" << std::endl;
    else if (dLiteral > std::numeric_limits<float>::max())
        std::cout << "inff" << std::endl;
    else if (dLiteral < -std::numeric_limits<float>::max())
        std::cout << "-inff" << std::endl;
    else
    {
        size_t setPre = _setprecision(value, isFloat);
        if (setPre != 0)
            std::cout << std::fixed << std::setprecision(setPre) << convertFloat << "f" << std::endl;
        else
            std::cout << std::fixed << convertFloat << "f" << std::endl;
    }
}

static void _printDouble(double dLiteral, bool errFlag)
{
    double convertDouble = static_cast<double>(dLiteral);

    std::cout << "double: ";
    if (errFlag == true || convertDouble != convertDouble)
        std::cout << "impossible" << std::endl;
    else
        std::cout << convertDouble << std::endl;
}

/* for check */

static bool _isNan(const std::string& value)
{
    if (value == "nan" || value == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return true;
    }
    return false;
}

static size_t _setprecision(const std::string& value, bool isFloat)
{
    size_t  strStart = value.find('.');
    if (strStart == std::string::npos)
        return 0;
    size_t  remainLen = value.length() - 1 - strStart;
    if (remainLen > 0 && isFloat == true)
        remainLen--;
    if (remainLen <= 1)
        return 1;
    return remainLen;
}

static bool _checkValid(char* pos, bool& isFloat)
{
    std::string remaining(pos);

    if (remaining.empty() == true)
        return true;
    if (remaining[0] == 'f' && remaining[1] == '\0')
    {
        isFloat = true;
        return true;
    }
    return false;
}

