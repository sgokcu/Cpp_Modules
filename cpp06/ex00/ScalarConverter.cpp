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
    double d;
    bool isFloat = false;

    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c = literal[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(i);
        d = static_cast<double>(i);

        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" ||
        literal == "+inff" || literal == "-inff") {

        if (literal[literal.length() - 1] == 'f') isFloat = true;
        d = std::strtod(literal.c_str(), NULL);

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << d << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }

    try {
        if (!literal.empty() && literal[literal.length() - 1] == 'f') {
            isFloat = true;
		d = std::atof(literal.c_str());
        } else {
		d = std::strtod(literal.c_str(), NULL);
        }

        int i = static_cast<int>(d);
        char c = static_cast<char>(i);
        float f = static_cast<float>(d);

        std::cout << "char: ";
        if (d < 0 || d > 127 || std::isnan(d))
            std::cout << "impossible" << std::endl;
        else if (!std::isprint(c))
            std::cout << "Non displayable" << std::endl;
        else
            std::cout << "'" << c << "'" << std::endl;

        std::cout << "int: ";
        if (d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min() || std::isnan(d))
            std::cout << "impossible" << std::endl;
        else
            std::cout << i << std::endl;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;

        std::cout << "double: " << d << std::endl;

    } catch (...) {
        std::cout << "Error: invalid input" << std::endl;
    }
}
