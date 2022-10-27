#include <string>

#ifndef EX01_CONTACT_HPP
#define EX01_CONTACT_HPP

class Contact
{
private:
    std::string CutString(std::string str);
    std::string  PrepareToPrint(std::string str);

public:
    int id;
    std::string firstName;
    std::string lastname;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;

    Contact();
    Contact(int cId, std::string fName, std::string lName, std::string nName,
            std::string pNumber, std::string dSecret);
    void DisplayContactInLine(int index);
    void DisplayContact();

};

#endif //EX01_CONTACT_HPP
