#include "PhoneBook.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <string>

PhoneBook::PhoneBook()
{
    for (int i = 0; i < 8; ++i)
    {
        contacts[i].id = -1;
    }
}

int PhoneBook::GetOldestContact()
{
    int currentIndex = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (contacts[i].id == -1)
            return i;
        if (contacts[i].id < contacts[currentIndex].id)
            currentIndex = i;
    }
    return currentIndex;
}

void PhoneBook::AddContact(Contact newContact)
{
    contacts[GetOldestContact()] = newContact;
}

void PhoneBook::AddContactFromUser()
{
    static int id = GetContactsCount();
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
    ClearScreen();
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
    for (int i = 0; i <= 7; ++i)
    {
        if (contacts[i].id > 0)
            contacts[i].DisplayContactInLine(i + 1);
    }
    std::cout << "___________________________________________" << std::endl;
    DisplayContact(GetIndexFromUser());
}

void PhoneBook::DisplayContact(int index)
{
    contacts[index].DisplayContact();
    std::cout << "\nPress any key to return to main menu";
    std::cin.get();
    std::cin.get();
}

int PhoneBook::GetIndexFromUser()
{
    std::string input;
    int intInput = -1;
    while (true)
    {
        std::cout << "Please enter contact index: " << std::endl;
        std::cin >> input;
        intInput = atoi(&input[0]);
        if (intInput >= 1 && intInput <= GetContactsCount())
            break;
    }
    return intInput - 1;
}

void PhoneBook::ClearScreen()
{
    std::cout << "\x1B[2J\x1B[H";
}

void PhoneBook::MainMenu()
{
    std::string answer;
    AsciiArt();
    usleep(2000000);
    while (true)
    {
        ClearScreen();
        std::cout << "MAIN MENU" << std::endl;
        std::cout << "1. Add contact" << std::endl;
        std::cout << "2. Search" << std::endl;
        std::cout << "3. Exit" << std::endl;
        std::cout << "PLEASE ENTER DIGIT FROM 1 TO 3:" << std::endl;
        std::cin >> answer;
        if (answer.compare("3") == 0 || answer.compare("EXIT") == 0)
        {
            ClearScreen();
            break;
        }
        else if (answer.compare("1") == 0 || answer.compare("ADD") == 0)
            AddContactFromUser();
        else if (answer.compare("2") == 0 || answer.compare("SEARCH") == 0)
            Search();
    }
}

void PhoneBook::AsciiArt()
{
std::cout <<
"           ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣾⣿⠿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⠀⠀⠀⠀⠀⠀⠀⢀⣤⣶⣤⣤⣴⣿⠟⠁⠀⠈⠛⠿⣿⣿⣶⣶⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⢀⣴⣶⣇⠀⢀⣴⣿⠟⠉⠉⠙⠛⠁⠀⠀⠀⠀⠀⠀⠀⠈⠉⠻⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⢀⣿⡟⠙⢿⣿⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠸⣿⡇⠀⠀⠀⠀⠀⢀⡴⠶⢦⣄⣀⣤⠾⠛⠛⣧⡀⠀⠀⠀⠀⠀⠀⠈⠛⢿⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⢠⣿⣇⠀⠀⠀⠀⣴⠋⠀⠀⠀⠈⠉⠁⠀⠀⠀⠈⠻⣦⣤⡤⠶⠻⢿⣦⠀⠀⢻⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⢸⣿⠉⢳⣶⢶⡿⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠀⠀⠀⠀⠀⣿⠁⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠘⣿⣄⡾⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠄⠀⠀⠀⠀⢠⡼⠋⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⢹⡿⠁⠀⢀⣾⡇⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⡀⠀⠀⠀⠀⠀⠠⣝⢦⡀⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⢀⣿⠇⠀⠀⠘⣿⠇⠀⠀⢀⠎⠀⠀⠀⠘⠛⠛⠿⠆⠀⠀⠀⠀⠠⣝⢧⡳⡄⣸⣿⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⢸⣿⠀⠀⠀⠀⠀⠀⢠⡾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢢⣜⢷⣽⣷⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⢸⡏⠀⠀⠀⠀⠀⠀⢿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠆⣹⣿⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⢸⣇⠀⠀⠀⠀⠀⠀⠈⠛⠂⠀⠀⠀⠀⢠⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠘⣿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⢸⣿⠀⠀⣾⣤⣀⣀⣀⢀⣀⣀⣀⡤⠔⠚⢿⣷⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⣿⣇⠀⠻⠳⢤⣈⣉⠉⠉⠀⣀⣀⣤⠖⠋⠟⠀⠀⠀⠀⠀⠀⢀⣀⣠⣾⣿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⠘⣿⣆⠀⠀⠀⠈⠙⣛⣛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⠿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⠀⠘⢿⣧⡀⠀⠀⠈⠛⠛⠃⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⠀⠀⠈⠻⣿⣦⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣿⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⠀⠀⠀⠀⠈⠙⠿⣿⣶⣦⣤⣤⣤⣤⣶⣶⣿⠿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠉⠉⠉⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"           ⠀⠀⠀⠀⠀⠀⠀⠀  LOADING...⠀⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
"\n"
"                  ___  __  _ ___                       \n"
"                 ( _ )/  \\( ) __|                      \n"
"                 / _ \\ () |/\\__ \\                      \n"
"                 \\___/\\__/  |___/_                    \n"
" | _ \\ || |/ _ \\| \\| | __| _ )/ _ \\ / _ \\| |/ /\n"
" |  _/ __ | (_) | .` | _|| _ \\ (_) | (_) | ' < \n"
" |_| |_||_|\\___/|_|\\_|___|___/\\___/ \\___/|_|\\_\\\n"
"                                               ";
}
