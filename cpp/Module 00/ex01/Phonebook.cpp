#include "./Phonebook.hpp"

void addContact(Contact &contact)
{
    std::cout << "Enter first name";
    std::getline(std::cin, contact.firstname);
    std::cout << "Enter last name";
    std::getline(std::cin, contact.lastname);
    std::cout << "Enter nickname";
    std::getline(std::cin, contact.nickname);
    std::cout << "Enter Phone Number";
    std::getline(std::cin, contact.phonenumber)
    std::cout << "Enter darkest secret";
    std::getline(std::cin, contact.darkestsecrect);
}

void searchContact(Contact contacts[])
{
}




