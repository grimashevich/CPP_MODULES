#include "Contact.hpp"

Contact::Contact()
{

}

Contact::Contact(int cId, std::string fName, std::string lName, std::string pNumber, std::string dSecret)
{
    id = cId;
    firstName = fName;
    lastname = lName;
    phoneNumber = pNumber;
    darkestSecret = dSecret;
}