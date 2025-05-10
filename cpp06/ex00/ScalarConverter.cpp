#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	if(this != &copy)
		*this = copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
    double d = 0.0;
    float f = 0.0f;
    int i = 0;
    char c = 0;

    // CHAR literal: single non-digit character
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    // FLOAT literal: ends with 'f'
    else if (literal.find('f') != std::string::npos && literal != "nanf" &&
             literal != "+inff" && literal != "-inff") {
        f = std::atof(literal.c_str());
        d = static_cast<double>(f);
        i = static_cast<int>(f);
        c = static_cast<char>(i);
    }
    // DOUBLE or PSEUDO-literal
    else {
        d = std::atof(literal.c_str());
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
    }

    // CHAR
    std::cout << "char: ";
    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" ||
        literal == "+inff" || literal == "-inff" ||
        d < 0 || d > 127 || std::isnan(d))
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;

    // INT
    std::cout << "int: ";
    if (std::isnan(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
        std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;

    // FLOAT
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f;
    if (literal != "nanf" && literal != "+inff" && literal != "-inff")
        std::cout << "f" << std::endl;
    else
        std::cout << std::endl;

    // DOUBLE
    std::cout << "double: " << d << std::endl;
}
