#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./WrongCat.hpp"

int main(void)
{
    std::cout << "=========================[Right implementation]=========================" << std::endl;
    {
        const Animal*   meta = new Animal();
        const Animal*   dogdog = new Dog();
        const Animal*   catcat = new Cat();

        std::cout << std::endl;

        std::cout << "meta type: " << meta->getType() << " ";
        meta->makeSound();
        std::cout << std::endl;

        std::cout << "dogdog type: " << dogdog->getType() << " ";
        dogdog->makeSound();
        std::cout << std::endl;

        std::cout << "catcat type: " << catcat->getType() << " ";
        catcat->makeSound();
        std::cout << std::endl;

        delete meta; meta = NULL;
        delete dogdog; dogdog = NULL;
        delete catcat; catcat = NULL;
    }

    std::cout << "\n=========================[Wrong implementation]=========================" << std::endl;
    {
        const WrongAnimal*  wrongmeta = new WrongAnimal();
        const WrongAnimal*  wrongcat = new WrongCat();

        std::cout << std::endl;

        std::cout << "wrongmeta type: " << wrongmeta->getType() << " ";
        wrongmeta->makeSound();
        std::cout << std::endl;

        std::cout << "wrongcat type: " << wrongcat->getType() << " ";
        wrongcat->makeSound();
        std::cout << std::endl;

        delete wrongmeta; wrongmeta = NULL;
        delete wrongcat; wrongcat = NULL;
    }

    return 0;
}
