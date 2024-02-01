#include <iostream>
#include <cmath>
#include <limits>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <cerrno>

int main(int ac, char **av) {
    char* pos = NULL;
    std::string str = av[1];
    errno = 0;
    double  d = std::strtod(str.c_str(), &pos);
    if (errno == ERANGE)
        std::cout << "strtod-err: " << pos << ", d: " << d << std::endl;
        // std::cout << "============ERANGE============" << std::endl;

    size_t i = str.find(pos[0]);
    if (i != std::string::npos) {
        std::cout << "** find: " << i << std::endl;
    }

    char c = static_cast<char>(d);
    std::cout << std::fixed << std::setprecision(10);
    if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || !std::isprint(c))
        std::cerr << "char: impossible, f: " << d << std::endl;
    if (/*c != c || */c < std::numeric_limits<char>::min() || c > std::numeric_limits<char>::max() || !std::isprint(c))
        std::cerr << "char: impossible, f: " << c << std::endl;

    // float f = static_cast<float>(d);
    // if (f != f)
    //     std::cerr << "float: nono" << std::endl;
    // else if (f == std::numeric_limits<float>::infinity())
    //     std::cerr << "float: inf" << std::endl;

    float f = static_cast<float>(d);
    if (f != f)
        std::cerr << "float: nono" << std::endl;
    else if (std::isinf(f))
        std::cerr << "float: inf" << std::endl;

    double D = static_cast<double>(d);
    if (D != D)
        std::cerr << "double: nono" << std::endl;
    else if (D == std::numeric_limits<double>::infinity())
        std::cerr << "double: inff" << std::endl;

    std::cout << "======================================" << std::endl;
    std::cout << std::fixed << static_cast<char>(d) << std::endl;
    std::cout << std::fixed << static_cast<int>(d) << std::endl;
    std::cout << std::fixed << static_cast<float>(d) << std::endl;
    std::cout << std::fixed << static_cast<double>(d) << std::endl;
}
