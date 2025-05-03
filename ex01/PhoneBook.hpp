#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>


class PhoneBook{
    private:
        Contact _contacts[8];
        int _totalcontacts;
        int _index;
    public:
        PhoneBook();
        ~PhoneBook();
        void    add_contacts(void);
        void    search_contacts(void);
}