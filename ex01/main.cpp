#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

void AddContacts(PhoneBook *phonebook);

int main()
{
    PhoneBook phonebook;
    AddContacts(&phonebook);
    phonebook.MainMenu();
    return 0;
}

void AddContacts(PhoneBook *phonebook)
{
    phonebook->AddContact(Contact(1,
                                 "Kosya",
                                 "Grimashevich",
                                 "eclown",
                                 "899988555",
                                 "He is not really clown"));
    phonebook->AddContact(Contact(2,
                                 "Vitya",
                                 "Lantsev",
                                 "bebek",
                                 "892548555",
                                 "He is not really bebek"));
    phonebook->AddContact(Contact(3,
                                 "Elon",
                                 "Mask",
                                 "TweeterKing",
                                 "12345",
                                 "He is Iron man"));
    phonebook->AddContact(Contact(4,
                                 "User 4",
                                 "---",
                                 "user4",
                                 "44444",
                                 "secret 4"));
    phonebook->AddContact(Contact(5,
                                 "User 5",
                                 "---",
                                 "user5",
                                 "5555",
                                 "secret 5"));
    phonebook->AddContact(Contact(6,
                                 "User 6",
                                 "---",
                                 "user6",
                                 "6666",
                                 "secret 6"));
    phonebook->AddContact(Contact(7,
                                 "User 7",
                                 "---",
                                 "user7",
                                 "7777",
                                 "secret 7"));
    phonebook->AddContact(Contact(8,
                                 "User 8",
                                 "---",
                                 "user8",
                                 "8888",
                                 "secret 8"));
}