#ifndef EX01_PHONEBOOK_HPP
#define EX01_PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];

    void AddContact(Contact newContact);
    std::string UserTextInput(std::string msg);
    int GetContactsCount();
public:
    PhoneBook();
    int getOldestContact();
    void addContactFromUser();
};

#endif //EX01_PHONEBOOK_HPP
