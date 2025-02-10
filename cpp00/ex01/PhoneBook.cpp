#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>//setw
#include <cstdlib>

PhoneBook::PhoneBook()
{
    this->dsize = 0;
    this->size = 0;
}

int s_isdigit(char c)
{
    if(c >= '0' && c <= '9')
        return 1;
    return 0;
}


void PhoneBook::ADD()
{
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string darkest_secret;
    std::string phone_number;
    int err;

    if(this->size == 8)
        this->size = 0;
    if(this->dsize != 8)
        this->dsize++;
    while(1)
    {
        std::cout << "First Name:";
        std::getline(std::cin, first_name);
        if(std::cin.eof())
            return ;
        std::cout << "Last Name:";
        std::getline(std::cin, last_name);
        if(std::cin.eof())
            return ;
        std::cout << "Nickname:";
        std::getline(std::cin, nickname);
        if(std::cin.eof())
            return ;
        while(1)
        {
            std::cout << "Phone Number:";
            std::getline(std::cin, phone_number);
            if(std::cin.eof())
                return ;
            for(int i = 0; phone_number[i]; i++)
            {
                err = 0;
                if(!s_isdigit(phone_number[i]))
                {
                    std::cout << "Please only enter digits!" << std::endl;
                    err = 1;
                    break;
                }
            }
            if(err == 1)
                continue;
            break;
        }
        std::cout << "Darkest Secret:";
        std::getline(std::cin, darkest_secret);
        if(std::cin.eof())
            return ;
        if(first_name.empty() || last_name.empty() || nickname.empty() || darkest_secret.empty())
        {
            std::cout << "You cannot leave the slots empty." << std::endl;
            continue;
        }
    break;
    }
    PhoneBook::contacts[this->size].setFirstName(first_name);
    PhoneBook::contacts[this->size].setLastName(last_name);
    PhoneBook::contacts[this->size].setNickname(nickname);
    PhoneBook::contacts[this->size].setDarkestSecret(darkest_secret);
    PhoneBook::contacts[this->size].setPhoneNumber(phone_number);
    this->size++;
}

std::string PhoneBook::fixSize(std::string str)
{
    if(str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::SEARCH()
{
    int index;
    std::string index_c;
    std::string first_name;
    std::string last_name;
    std::string nickname;

    if(this->dsize == 0)
    {
        std::cout << "There is nothing to display." << std::endl;
        return ;
    }

    std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|"
    << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;

    for(int i = 0; i < this->dsize; i++)
    {
        std::cout << std::setw(10) << i << "|" << std::setw(10) << fixSize(contacts[i].getFirstName()) << "|"
        << std::setw(10) << fixSize(contacts[i].getLastName()) << "|" << std::setw(10) 
        << fixSize(contacts[i].getNickname()) << std::endl;
    }
    while(1)
    {
        std::cout << "Enter the number you want to display:" << std::endl;
        std::getline(std::cin, index_c);
        if(std::cin.eof())
            return ;
        try
        {
            index = std::atoi(index_c.c_str());
            if(index == -1)
                throw std::invalid_argument("Invalid index");
        }
        catch(std::invalid_argument& e)
        {
            std::cout << "Error: " << e.what() << std::endl;
            continue;
        }
        if(index >= dsize)
        {
            std::cout << "Invalid index!!" << std::endl;
            continue;
        }
        break;
    }
    std::cout << "Index: " << index << std::endl;
    std::cout << "First Name: " << this->contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << this->contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << this->contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: "<< this->contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << this->contacts[index].getDarkestSecret() << std::endl;
    std::cout << std::endl;
}


