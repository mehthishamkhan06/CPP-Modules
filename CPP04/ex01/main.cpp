#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

#define ARRAY_SIZE 4

int main()
{
    std::cout << "🔄 Creating Animals Array:\n";
    Animal* animals[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n🧠 Setting ideas in Dog and Cat:\n";
    Dog* dog = dynamic_cast<Dog*>(animals[0]);
    Cat* cat = dynamic_cast<Cat*>(animals[1]);

    if (dog)
        dog->setIdea(0, "Guard the house");

    if (cat)
        cat->setIdea(0, "Climb the curtains");

    std::cout << "\n📢 Making sounds:\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        animals[i]->makeSound();
    }

    std::cout << "\n🧪 Deep Copy Test:\n";
    Dog originalDog;
    originalDog.setIdea(0, "Eat food");

    Dog copiedDog = originalDog; // Triggers copy constructor
    copiedDog.setIdea(0, "Guard the house");

    std::cout << "Original Dog idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog idea:   " << copiedDog.getIdea(0) << std::endl;

    std::cout << "\n🧹 Cleaning up:\n";
    for (int i = 0; i < ARRAY_SIZE; i++) {
        delete animals[i];
    }

    return 0;
}
