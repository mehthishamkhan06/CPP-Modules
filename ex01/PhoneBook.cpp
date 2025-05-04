#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    this->_currentIndex = 0;
    this->_contactCount = 0;
    return ;
}

PhoneBook::~PhoneBook(){
    return ;
}

void PhoneBook::addContact(Contact contact){
    if (this->_contactCount < 8)
        this->_contactCount++;
    this->_contacts[this->_currentIndex] = contact;
    this->_currentIndex = (this->_currentIndex + 1) % 8; 
    std::cout << "✅ Contact added successfully." << std::endl;
}

void    PhoneBook::displaySummary(int index) const
{
    std::cout << "|" << std::setw(10) << index + 1 << "|";
    if (this->_contacts[index].getFirstName().length() > 10)
        std::cout << std::setw(10) << this->_contacts[index].getFirstName().substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << this->_contacts[index].getFirstName();
    std::cout << "|";
    if (this->_contacts[index].getLastName().length() > 10)
        std::cout << std::setw(10) << this->_contacts[index].getLastName().substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << this->_contacts[index].getLastName();
    std::cout << "|";
    if (this->_contacts[index].getNickName().length() > 10)
        std::cout << std::setw(10) << this->_contacts[index].getNickName().substr(0, 9) + ".";
    else
        std::cout << std::setw(10) << this->_contacts[index].getNickName();
    std::cout << "|" << std::endl;  
}

void PhoneBook::displayContacts() const {
    std::cout << "+----------+----------+----------+----------+\n";
    std::cout << "|   Index  |First Name| Last Name| Nickname |\n";
    std::cout << "+----------+----------+----------+----------+\n";

    for (int i = 0; i < this->_contactCount; i++) {
        this->displaySummary(i);
    }
    std::cout << "+----------+----------+----------+----------+\n";
}

void PhoneBook::FindContacts() const{

    std::string index;
    PhoneBook::displayContacts();
    while(true)
    {
        std::cout << "Enter index of contact to view: ";
        if (!std::getline(std::cin, index))
            return ;
        if (index.length() == 1 && std::isdigit(index[0]))
        {
            int i = index[0] - '0' - 1;
            if (i >= 0 && i < this->_contactCount)
            {
                this->_contacts[i].displayFull();
                break;
            }
            else
                std::cout << "Invalid index. Please try again." << std::endl;
        }
    }
}