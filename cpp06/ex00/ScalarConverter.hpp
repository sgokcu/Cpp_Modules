#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cctype>
#include <exception>
#include <iomanip>
#include <cmath>
#include <limits>
#include <cstdlib>

class ScalarConverter
{
private:
    ScalarConverter();///////////////////////////////////////////////
    ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);
    ~ScalarConverter();
public:
    static void convert(const std::string &literal);
};
bool isInteger(const std::string& str);

#endif
//compiler time bu static castler