#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <cstdlib>

class PhoneBook
{
private:
    int dsize;
    int size;
    Contact contacts[8];
    std::string fixSize(std::string str);

public:
    void ADD();
    void SEARCH();
    PhoneBook();
};

int s_isdigit(char c);

#endif
