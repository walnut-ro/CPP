#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cctype>
#include <cmath>

static void printChar(double n)
{
    if (std::isnan(n) || std::isinf(n) || n < 0 || n > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(n)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
}

static void printInt(double n)
{
    if (std::isnan(n) || std::isinf(n) ||
        n < static_cast<double>(std::numeric_limits<int>::min()) ||
        n > static_cast<double>(std::numeric_limits<int>::max()))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(n) << std::endl;
}

static void printFloat(double n)
{
    if (std::isnan(n))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(n))
        std::cout << "float: " << (n < 0 ? "-inff" : "+inff") << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << static_cast<float>(n) << "f" << std::endl;
}

static void printDouble(double n)
{
    if (std::isnan(n))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(n))
        std::cout << "double: " << (n < 0 ? "-inf" : "+inf") << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1)
                  << static_cast<double>(n) << std::endl;
}

static bool isSpecialLiteral(const std::string &s)
{
    return (s == "nan" || s == "nanf" ||
            s == "+inf" || s == "+inff" ||
            s == "-inf" || s == "-inff");
}

static bool isIntegerLiteral(const std::string &s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.length())
        return false;
    for (; i < s.length(); ++i)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

void ScalarConverter::convert(const std::string &arg)
{
    try
    {
        double value;

        if (isSpecialLiteral(arg))
        {
            value = (arg.find('f') != std::string::npos)
                        ? std::strtof(arg.c_str(), nullptr)
                        : std::strtod(arg.c_str(), nullptr);
        }
        else if (arg.length() == 1 && std::isprint(arg[0]) && !std::isdigit(arg[0]))
        {
            value = static_cast<double>(arg[0]);
        }
        else if (arg.back() == 'f' && arg.find('.') != std::string::npos)
        {
            value = std::stof(arg);
        }
        else if (arg.find('.') != std::string::npos)
        {
            value = std::stod(arg);
        }
        else if (isIntegerLiteral(arg))
        {
            value = std::stoi(arg);
        }
        else
        {
            throw std::invalid_argument("Unrecognized literal format");
        }

        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
