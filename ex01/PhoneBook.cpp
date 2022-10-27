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
    newContact.nickName = UserTextInput("Enter nickname");
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

void PhoneBook::Search()
{
    int pBookLength = GetContactsCount();
    if (pBookLength == 0)
    {
        std::cout << "There are no contacts in your phonebook..." << std::endl;
        std::cout << "Please press any key to enter main menu";
        std::cin.get();
        return;
    }
    std::cout << "     index|First name| Last name|  Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < 7; ++i)
    {
        if (contacts[i].id > 0)
            contacts[i].DisplayContactInLine(i);
    }
    std::cout << "___________________________________________" << std::endl;
    DisplayContact(GetIndexFromUser());
}

void PhoneBook::DisplayContact(int index)
{

    contacts[index].DisplayContact();
}

int PhoneBook::GetIndexFromUser()
{
    int input = -1;
    while (true)
    {
        std::cout << "Please enter contact index: " << std::endl;
        std::cin >> input;
        if (input >= 0 && input < GetContactsCount())
            break;
    }
    return input;
}

