#include "./Dog.hpp"
#include "./Cat.hpp"
#include "./WrongCat.hpp"

int main(void)
{
    std::cout << "=========================[Right implementation]=========================" << std::endl;
    {
        const int   N = 16;
        Animal      *animals[N];

        std::cout << "-------------array of animals-------------" << std::endl;
        for (int i = 0; i < N; i++)
        {
            if (i % 2 == 0)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }
        std::cout << "------------------------------------------" << std::endl;
        for (int i = 0; i < N; i++)
        {
            std::cout << "--animals[" << i << "]--" << std::endl;
            std::cout << "🍄 animal type is " << animals[i]->getType() << "and it'll be destroied" << std::endl;
            animals[i]->makeSound();
            delete animals[i];
        }
        std::cout << "------------------------------------------" << std::endl;

        std::cout << "----------deep copy implemetaion----------" << std::endl;
        Dog         barkbark;
        Dog         whalwhal(barkbark);
        Dog*        gangme = new Dog(barkbark);
        const int   index = 8;

        std::cout << "------------------------------------------" << std::endl;
        std::cout << "[before] 🐶barkbark's ideas(" << index << "): " << barkbark.getBrain()->getIdeas(index) << std::endl;
        std::cout << "[before] 🐶whalwhal's ideas(" << index << "): " << whalwhal.getBrain()->getIdeas(index) << std::endl;
        std::cout << "[before] 🐶gangme's ideas(" << index << "): " << gangme->getBrain()->getIdeas(index) << std::endl;

        barkbark.getBrain()->setIdeas(index, "bark!! yammy~~~~~~🦴");
        whalwhal.getBrain()->setIdeas(index, "whal!! yammy~~~~~~🍗");
        gangme->getBrain()->setIdeas(index, "haha~~ I'm so cute!😚");

        std::cout << "[after] 🐶barkbark's ideas(" << index << "): " << barkbark.getBrain()->getIdeas(index) << std::endl;
        std::cout << "[after] 🐶whalwhal's ideas(" << index << "): " << whalwhal.getBrain()->getIdeas(index) << std::endl;
        std::cout << "[after] 🐶gangme's ideas(" << index << "): " << gangme->getBrain()->getIdeas(index) << std::endl;

        std::cout << "------------------------------------------" << std::endl;
        delete gangme;
    }
    std::cout << "------------------------------------------" << std::endl;

    std::cout << "\n=========================[Wrong implementation]=========================" << std::endl;
    {

    }

    return 0;
}
