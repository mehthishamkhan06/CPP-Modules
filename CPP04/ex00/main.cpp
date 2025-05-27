#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* k = new WrongDog();
    const WrongAnimal* l = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << k->getType() << " " << std::endl;
    std::cout << l->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    k->makeSound(); //will output the wrongcat sound!
    l->makeSound();
    meta2->makeSound();
    delete meta;
    delete i;
    delete j;
    delete meta2;
    delete k;
    delete l;
    return(0);
}