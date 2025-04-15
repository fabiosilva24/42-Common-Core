#include "Contact.hpp"

void Contact::set_firstname(const std::string& firstname)
{
    this->firstname = firstname;
}
void Contact::set_lastname(const std::string& lastname)
{
    this->lastname = lastname;
}
void Contact::set_nickname(const std::string& nickname)
{
    this->nickname = nickname;
}
void Contact::set_darkestsecret(const std::string& darkestsecret)
{
    this->darkestsecret = darkestsecret;
}
void Contact::set_phonenumber(const std::string& phonenumber)
{
    this->phonenumber = phonenumber;
}
std::string Contact::get_firstname() const
{
    return (firstname);
}

std::string Contact::get_lastname() const
{
    return (lastname);
}
std::string Contact::get_nickname() const
{
    return (nickname);
}
std::string Contact::get_phonenumber() const
{
    return (phonenumber);
}
std::string Contact::get_darkestsecret() const
{
    return (darkestsecret);
}