#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
    this->_currentIndex = 0;
    this->_contactCount = 0;
    return ;
}

PhoneBook::~PhoneBook(){
    return ;
}

void PhoneBook::addContact(const Contact contact){
    if (this->_contactCount < 8)
        this->_contactCount++;
    this->_contacts[this->_currentIndex] = contact;
    this->_currentIndex = (this->_currentIndex + 1) % 8; // Wrap around to the beginning
    std::cout << "✅ Contact added successfully." << std::endl;
}

void    Contact::displaySummary(int index)
{
    std::cout << "|" << std::setw(5) << index + 1 << "|";
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
    std::cout << "+----------+----------+----------+----------+" << std::endl;  
}

static void PhoneBook::displayContacts() const {
    std::cout << "+----------+----------+----------+----------+\n";
    std::cout << "|   Index  |First Name| Last Name| Nickname |\n";
    std::cout << "+----------+----------+----------+----------+\n";

    for (int i = 0; i < this->_contactCount; i++) {
        this->_contacts[i].displaySummary(i);
    }
    std::cout << "+----------+----------+----------+----------+\n";
}

void PhoneBook::FindContacts(void) const{

    std::string index;
    PhoneBook::displayContacts();
    std::cout << "Enter index of contact to view: ";
    if (!std::getline(std::cin, index))
        return ;
    whilw(true)
    {
        if (index.length() == 1 && std::isdigit(index[0]))
        {
            int i = index[0] - '0';
            if (i >= 0 && i < this->_contactCount)
            {
                this->_contacts[i].displayFull();
                break;
            }
            else
                std::cout << "Invalid index. Please try again." << std::endl;
        }
        else
            std::cout << "Invalid input. Please enter a number." << std::endl;
    }
}