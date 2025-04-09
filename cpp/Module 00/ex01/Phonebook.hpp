#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class Phonebook{
    private:
        Contact contacts[8];
        int index;
    public:
            void addContact(const Contact& contacts);
            void searchContact();
};

#endif