#include "Contact.hpp"
#include <iostream>
#include <string>

Contact::Contact()
{

}

Contact::Contact(int cId, std::string fName, std::string lName, std::string nName,
                 std::string pNumber, std::string dSecret)
{
    id = cId;
    firstName = fName;
    lastname = lName;
    nickName = nName;
    phoneNumber = pNumber;
    darkestSecret = dSecret;
}

std::string Contact::CutString(std::string str)
{
    std::string result;
    if (str.length() > 10)
    {
        result = str.substr(0, 10);
        result[9] = '.';
        return result;
    }
    return str;
}

std::string Contact::PrepareToPrint(std::string str)
{
    std::string result;
    int strLength = 0;
    result = CutString(str);
    strLength = result.length();
    if (strLength < 10)
    {
        std::string addon = std::string(10 - strLength, ' ');
        result = addon + result;
    }
    return result;
}


void Contact::DisplayContactInLine(int index)
{
    std::cout <<  PrepareToPrint(std::string(1, index + 48)) << "|";
    std::cout << PrepareToPrint(firstName) << "|";
    std::cout << PrepareToPrint(lastname) << "|";
    std::cout << PrepareToPrint(nickName) << std::endl;
}

void Contact::DisplayContact()
{
    ClearScreen();
    std::cout << "First Name....: " << firstName << std::endl;
    std::cout << "Last Name.....: " << lastname << std::endl;
    std::cout << "Nickname......: " << nickName << std::endl;
    std::cout << "Phone number..: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
}

void Contact::ClearScreen()
{
    std::cout << "\x1B[2J\x1B[H";
}
