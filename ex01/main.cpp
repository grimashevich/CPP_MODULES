#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    phonebook.addContactFromUser();
    phonebook.addContactFromUser();
    phonebook.addContactFromUser();
    std::cin.get();
/*
    Contact contact = Contact(0, "Elyas", "Clown",
                              "000555","He is not really clown");

    (void) contact;
*/

    return 0;

}
