#include "Phonebook.hpp"

Phonebook::Phonebook() : index(0) 
{}
void Phonebook::addContact(const Contact& contact)
{
<<<<<<< HEAD
    Contact new_contact;
    std::cout << "Enter first name";
    std::getline(std::cin, contact.firstname);
    std::cout << "Enter last name";
    std::getline(std::cin, contact.lastname);
    std::cout << "Enter nickname";
    std::getline(std::cin, contact.nickname);
    std::cout << "Enter Phone Number";
    std::getline(std::cin, contact.phonenumber);
    std::cout << "Enter darkest secret";
    std::getline(std::cin, contact.darkestsecrect);

    contacts[index] = new_contact; //overwrite oldest if full
    index = (index + 1) % 8;
=======
    contacts[index] = contact;
    index = (index + 1) % 8;    
>>>>>>> b72cbfd62cd279a438e007f0f6504db19cbc3257
}
void Phonebook::searchContact(const Contact& contact)
{
<<<<<<< HEAD
    if (contacts_tosearch == 0 && contacts[0].get_firstname().empty())
    {
        std::cout << "No Contacts to search\n";
        return;
    }
    std::cout << "Index" << " " << "|" << std::setw(10) << "Firstname" << " " << "|" <<  std::setw(10) << "Lastname" << " " << "|" << std::setw(10) << "nickname" << " " << "|" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < 8; i++;)
    {
        std::cout << i << "|"
                << std::setw(10) << contacts[i].get_firstname() << " | "
                << std::setw(10) << contacts[i].get_lastname() << " | "
                << std::setw(10) << contacts[i].get_nickname() << std::endl;
    }
=======
    
>>>>>>> b72cbfd62cd279a438e007f0f6504db19cbc3257
}




