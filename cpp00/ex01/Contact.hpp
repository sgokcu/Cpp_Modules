#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string darkest_secret;
    std::string phone_number;

public:
    void setFirstName(std::string first_name);
    void setLastName(std::string last_name);
    void setNickname(std::string nickname);
    void setDarkestSecret(std::string darkeset_secret);
    void setPhoneNumber(std::string phone_number);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getDarkestSecret();
    std::string getPhoneNumber();
};

#endif
