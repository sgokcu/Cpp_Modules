#include "RPN.hpp"

int evaluate(const std::string& expr)
{
    std::stack<int> stack;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) 
    {
        if (token.length() == 1 && std::isdigit(token[0])) 
            stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/") 
        {
            if (stack.size() < 2)
                throw std::runtime_error("Invalid expression");

            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();

            if (token == "+") 
                stack.push(a + b);
            else if (token == "-") 
                stack.push(a - b);
            else if (token == "*") 
                stack.push(a * b);
            else if (token == "/") 
            {
                if (b == 0)
                    throw std::runtime_error("Division by zero");
                stack.push(a / b);
            }
        } 
        else
            throw std::runtime_error("Invalid token");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Invalid final stack");

    return stack.top();
}
