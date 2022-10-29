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
    void ClearScreen();
    void AsciiArt();

public:
    PhoneBook();
    void MainMenu();
    void AddContact(Contact newContact);
    int GetOldestContact();
    void AddContactFromUser();
    void Search();
};

#endif //EX01_PHONEBOOK_HPP
