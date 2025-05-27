#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>


class Animal
{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal &copy);
        Animal &operator=(const Animal &copy);
        virtual ~Animal() = 0; // Pure virtual destructor
        // Ensures that the class is abstract and cannot be instantiated
        // Pure virtual function makes this class abstract
        // Derived classes must implement this function

        virtual void makeSound() const = 0; // Pure virtual function
        std::string getType() const;
};
#endif