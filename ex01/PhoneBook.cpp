#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
    for (int i = 0; i < 8; ++i)
    {
        contacts[i].id = -1;
    }
}

int PhoneBook::getOldestContact()
{
    int currentIndex = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (contacts[i].id == -1)
            return i;
        if (contacts[i].id > contacts[currentIndex].id)
            currentIndex = i;
    }
    return currentIndex;
}

void PhoneBook::AddContact(Contact newContact)
{
    contacts[getOldestContact()] = newContact;
}

void PhoneBook::addContactFromUser()
{
    static int id = 0;
    Contact newContact;
    newContact.firstName = UserTextInput("Enter first name");
    newContact.lastname = UserTextInput("Enter last name");
    newContact.phoneNumber = UserTextInput("Enter phone number");
    newContact.darkestSecret = UserTextInput("Enter darkest secret");
    newContact.id = id++;
    AddContact(newContact);
    std::cout << "Contact added successfully" << std::endl;
    std::cout << "Contacts in phonebook: " << GetContactsCount() << " of 8" << std::endl;
}

std::string PhoneBook::UserTextInput(std::string msg)
{
    std::string input = "";
    while (input.empty())
    {
        std::cout << msg << std::endl;
        std::cin >> input;
    }
    return input;
}

int PhoneBook::GetContactsCount()
{
    int count = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (contacts[i].id != -1)
            count++;
    }
    return count;
}
