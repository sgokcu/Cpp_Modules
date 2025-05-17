#include "iter.hpp"

void printInt(int x) {
    std::cout << x << std::endl;
}

void printString(const std::string& str) {
    std::cout << str << std::endl;
}

int main() {
    int intArray[5] = {1, 2, 3, 4, 5};
    std::string strArray[3] = {"hello", "world", "!"};

    std::cout << "Integer array:" << std::endl;
    iter(intArray, 5, printInt);

    std::cout << "String array:" << std::endl;
    iter(strArray, 3, printString);

    return 0;
}
