#include "easyfind.hpp"

int main() {
    std::vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(20);
    v.push_back(60);


    try {
        std::vector<int>::iterator it = easyfind(v, 20);
        std::cout << "Found value  " << *it << std::endl;
        ++it;
        std::cout << "The value after the found value  " << *it << std::endl;

    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(v, 99);
        std::cout << "Found value  " << *it << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
