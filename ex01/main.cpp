#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    phonebook.AddContact(Contact(1,
                                 "Kosya",
                                 "Grimashevich",
                                 "eclown",
                                 "899988555",
                                 "He is not really clown"));
        phonebook.AddContact(Contact(2,
                                 "Vitya",
                                 "Lantsev",
                                 "bebek",
                                 "892548555",
                                 "He is not really bebek"));

    phonebook.Search();
    //std::cin.get();
/*
    Contact contact = Contact(0, "Elyas", "Clown",
                              "000555","He is not really clown");

    (void) contact;
*/

    return 0;

}
