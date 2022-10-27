#ifndef EX01_PHONEBOOK_HPP
#define EX01_PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];

    std::string UserTextInput(std::string msg);
    int GetContactsCount();
    void DisplayContact(int index);
    int GetIndexFromUser();

public:
    void AddContact(Contact newContact);
    PhoneBook();
    int getOldestContact();
    void addContactFromUser();
    void Search();
};

#endif //EX01_PHONEBOOK_HPP
