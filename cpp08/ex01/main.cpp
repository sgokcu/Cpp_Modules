#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        std::cout << "***************************************************" << std::endl;
        try {
            sp.addNumber(99);
        } 
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "***************************************************" << std::endl;
        Span empty(3);
        try {
            empty.shortestSpan();
        } 
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "***************************************************" << std::endl;
        empty.addNumber(42);
        try {
            empty.longestSpan();
        } 
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "***************************************************" << std::endl;
        Span bigSpan(10000);
        std::vector<int> bigVector;
        srand(time(0));
        for (int i = 0; i < 10000; ++i) {
            bigVector.push_back(rand());
        }
        bigSpan.addNumbers(bigVector.begin(), bigVector.end());
        std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Genaral exception: " << e.what() << std::endl;
    }
}
