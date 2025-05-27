#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"


// int main()
// {
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     delete j;//should not create a leak
//     delete i;

//     return 0;
// }

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "🔄 Creating Animals Array:\n";
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; ++i) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n🧠 Setting ideas in Dog and Cat:\n";
    Dog* realDog = dynamic_cast<Dog*>(animals[0]);
    Cat* realCat = dynamic_cast<Cat*>(animals[1]);

    if (realDog) realDog->setIdea(0, "Chase cats");
    if (realCat) realCat->setIdea(0, "Nap on the couch");

    std::cout << "\n📢 Making sounds:\n";
    for (int i = 0; i < size; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "\n🧪 Deep Copy Test:\n";
    Dog originalDog;
    originalDog.setIdea(0, "Guard the house");

    Dog copyDog = originalDog; // invokes copy constructor

    originalDog.setIdea(0, "Eat food");

    std::cout << "Original Dog idea: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog idea:   " << copyDog.getIdea(0) << std::endl;

    std::cout << "\n🧹 Cleaning up:\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];

    return 0;
}
