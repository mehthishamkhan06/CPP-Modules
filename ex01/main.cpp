#include "Contact.hpp"
#include "Contact.hpp"


int main(void)
{
    PhoneBook   phonebook;
    Contact contact;
    std::string command;

    while(true)
    {
        std::cout << "+-------------------------------------------+" << std::endl;
		std::cout << "|        Commands: ADD, SEARCH, EXIT        |" << std::endl;
		std::cout << "+-------------------------------------------+" << std::endl;
		std::cout << "Enter a Command: ";
        if (!std::getline(std::cin, command))
            break ;
        if (command == "EXIT")
            break ;
        else if (command == "ADD")
        {
            contact.setFirstName();
            contact.setLastName();
            contact.setNickName();
            contact.setPhoneNumber();
            contact.setDarkestSecret();
            phonebook.addContact(contact);
        }
        else if (command == "SEARCH")
            phonebook.FindContacts();
        else
            std::cout << "Invalid command. Please try again." << std::endl;
    }
    return (0);
}