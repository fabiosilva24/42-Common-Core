#include "Phonebook.hpp"

Phonebook::Phonebook() : index(0) 
{}
void Phonebook::addContact(const Contact& contact)
{
    contacts[index] = contact;
    index = (index + 1) % 8;    
}




