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

bool isInteger(const std::string& str) {
    if (str.empty())
        return false;

    std::size_t i = 0;

    if (str[i] == '-' || str[i] == '+') {
        if (str.length() == 1)
            return false;
        i++;
    }

    for (; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void ScalarConverter::convert(const std::string &literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    try
    {
        if(literal.length() == 1 && !std::isdigit(literal[0]))
        {
            c = literal[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
        }
        else if(literal.find('f') != std::string::npos)
        {
            f = static_cast<float>(literal.c_str(), NULL);
            i = static_cast<int>(f);
            c = static_cast<char>(i);
            d = static_cast<double>(f);
        }
        else if(literal.find('.') != std::string::npos)
        {
            d = strtod(literal.c_str(), NULL);
            f = static_cast<float>(d);
            i = static_cast<int>(d);
            c = static_cast<char>(i);
        }
        else if(isInteger(literal))
        {
            i = atoi(literal.c_str());
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);

        }
        else
            throw std::exception();
    }
    catch(const std::exception& e)
    {
    }
    std::cout << "char: ";
    if(std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "impossible" << std::endl;
    std::cout << "integer: ";
    if(literal == "+inff" || literal == "-inff" || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" || literal == "nan")
    std::cout << "impossible" << std::endl;
    else
        std::cout << i << std::endl;    
    std::cout << "Float: ";
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
    

}
