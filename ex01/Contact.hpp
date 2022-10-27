#include <string>

#ifndef EX01_CONTACT_HPP
#define EX01_CONTACT_HPP

class Contact
{
public:
    int id;
    std::string firstName;
    std::string lastname;
    std::string phoneNumber;
    std::string darkestSecret;

    Contact();
    Contact(int cId, std::string fName, std::string lName,
            std::string pNumber, std::string dSecret);
};

#endif //EX01_CONTACT_HPP
