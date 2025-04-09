#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>


class Contact{
    private:
            std::string firstname;
            std::string lastname;
            std::string nickname;
            std::string phonenumber;
            std::string darkestsecret;
    public:
        void set_firstname(const std::string& firstname);
        void set_lastname(const std::string& lastname);
        void set_nickname(const std::string& nickname);
        void set_phonenumber(const std::string& phonenumber);
        void set_darkestsecret(const std::string& darkestsecret);
        std::string Contact::get_firstname() const;
        std::string Contact::get_lastname() const;
        std::string Contact::get_nickname() const;
        std::string Contact::get_phonenumber() const;
        std::string Contact::get_darkestsecret() const;

};

#endif