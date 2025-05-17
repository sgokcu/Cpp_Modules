#include "Array.hpp"

int main() {
    try {
        Array<int> intArr(5);
        for (std::size_t i = 0; i < intArr.size(); ++i)
            intArr[i] = i * 10;

        std::cout << "int array:" << std::endl;
        for (std::size_t i = 0; i < intArr.size(); ++i)
            std::cout << intArr[i] << " ";
        std::cout << std::endl;

        Array<std::string> strArr(3);
        strArr[0] = "hello";
        strArr[1] = "world";
        strArr[2] = "!";

        std::cout << "string array:" << std::endl;
        for (std::size_t i = 0; i < strArr.size(); ++i)
            std::cout << strArr[i] << " ";
        std::cout << std::endl;

        // Copy test
        Array<std::string> copyStrArr = strArr;
        copyStrArr[1] = "cpp";
        std::cout << "original: " << strArr[1] << ", copy: " << copyStrArr[1] << std::endl;

        // Exception test
        std::cout << intArr[10] << std::endl; // Should throw
    }
    catch (const std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
