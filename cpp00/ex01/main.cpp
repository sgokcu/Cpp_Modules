#include "PhoneBook.hpp"
#include <iostream>

int main()
{
    PhoneBook phonbook;
    std::string input;

    while(1)
    {
        std::cout << "Enter the command you want to do:" << std::endl
        << "1) ADD" << std::endl << "2) SEARCH" << std::endl 
        << "3) EXIT" << std::endl << "->";

        std::getline(std::cin, input);
        if(std::cin.eof())
            break;
        if(input.empty())
            continue;
        if(input != "ADD" && input != "SEARCH" && input != "EXIT")
        {
             std::cout << "Please enter a valid input!!" << std::endl;
             continue;
        }
        if(input == "ADD")
            phonbook.ADD();
        else if(input == "SEARCH")
            phonbook.SEARCH();
        else if(input == "EXIT")
            return (0);
    }
}