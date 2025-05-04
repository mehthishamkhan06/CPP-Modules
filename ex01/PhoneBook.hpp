#ifndef PhoneBook_hpp
#define PhoneBook_hpp

#include <iostream>
#include <string>
#include "Contact.hpp"



class PhoneBook {

private:
    Contact _contacts[8]; // Array to store up to 8 contacts
    int _contactCount;    // Number of contacts currently stored
    int _currentIndex;    // Current index for adding new contacts
public:
    // Constructor
    PhoneBook();

    // Destructor
    ~PhoneBook();

    // Method to add a contact
    void addContact(Contact contact);

    void displaySummary(int index) const;
    // Method to display all contacts
    void FindContacts() const;
    // Method to display a summary of all contacts
    void displayContacts() const;
};

#endif
