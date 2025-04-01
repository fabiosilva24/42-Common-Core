#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook{
    private:
        Contact contacts[8];

    public:
            void addContact();
            void searchContact();
};