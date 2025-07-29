#include "RPN.hpp"

int main(int argc, char** argv) 
{
    if (argc < 2) 
    {
        std::cerr << "Error: Too few arguments." << std::endl;
        return 1;
    }
    try {
        std::string expression;
        for (int i = 1; i < argc; i++) 
        {
            expression += std::string(argv[i]);
            if (i < argc - 1)
                expression += " ";
        }
        int result = evaluate(expression);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error" << std::endl;
    }
}
