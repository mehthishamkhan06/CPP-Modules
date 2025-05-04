#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

class Contact {

    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nickname;
        std::string _phone_number;
        std::string _darkest_secret;

    public:
        // Constructor
        Contact();

        // Destructor
        ~Contact();

        // Setters for contact information these are not const as they modify the object
        void setFirstName(void);
        void setLastName(void);
        void setNickName(void);
        void setPhoneNumber(void);
        void setDarkestSecret(void);

        // Getters for contact information these are const as they do not modify the object
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickName(void) const;
        std::string getPhoneNumber(void) const;
        std::string getDarkestSecret(void) const;

        // Display methods
        void displayFull() const;
};

#endif
