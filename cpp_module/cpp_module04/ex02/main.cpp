#include "./Dog.hpp"
#include "./Cat.hpp"
// #include "./WrongCat.hpp"
#include "./WrongAnimal.hpp"

// static void _leak_check(void);

int main(void)
{
    // atexit(_leak_check);
    std::cout << "=========================[Right implementation]=========================" << std::endl;
    {
        const int   N = 3;
        Animal      *animals[N];

        std::cout << "-------------array of animals-------------" << std::endl;
        animals[0] = new Dog();
        animals[1] = new Cat();
        // animals[2] = new Animal();
        animals[2] = new Dog();

        std::cout << "------------------------------------------" << std::endl;
        for (int i = 0; i < N; i++)
        {
            std::cout << "--animals[" << i << "]--" << std::endl;
            std::cout << "🍄 animal type is " << animals[i]->getType() << " and it'll be destroied" << std::endl;
            animals[i]->makeSound();
            delete animals[i];
        }
    }
    std::cout << "------------------------------------------" << std::endl;

    std::cout << "\n=========================[Wrong implementation]=========================" << std::endl;
    {
        const int   N = 3;
        WrongAnimal *wrongAnimals[N];

        std::cout << "-------------array of wrongAnimals-------------" << std::endl;
        for (int i = 0; i < N; i++)
            wrongAnimals[i] = new WrongAnimal();
        std::cout << "------------------------------------------" << std::endl;
        for (int i = 0; i < N; i++)
        {
            std::cout << "--wrongAnimals[" << i << "]--" << std::endl;
            std::cout << "❌ wrongAnimal type is " << wrongAnimals[i]->getType() << " and it'll be destroied" << std::endl;
            wrongAnimals[i]->makeSound();
            delete wrongAnimals[i];
        }
    }
    std::cout << "------------------------------------------" << std::endl;

    return 0;
}

// static void _leak_check(void)
// {
//     system("leaks AbstractClass");
// }
