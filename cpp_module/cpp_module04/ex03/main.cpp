#include "./MateriaSource.hpp"
#include "./Character.hpp"

int main(void)
{
    std::cout << "================test1================" << std::endl;
    {
        IMateriaSource* book = new MateriaSource();
        book->learnMateria(new Ice());
        book->learnMateria(new Cure());

        ICharacter*     jihyun = new Character("jihyun");

        AMateria*       temp;
        temp = book->createMateria("ice");
        jihyun->equip(temp);
        delete temp; temp = NULL;

        temp = book->createMateria("cure");
        jihyun->equip(temp);
        delete temp; temp = NULL;

        ICharacter*     babo = new Character("babo");

        jihyun->use(0, *babo);
        jihyun->use(1, *babo);

        delete babo; babo = NULL;
        delete jihyun; jihyun = NULL;
        delete book; book = NULL;
    }

    std::cout << "================test2================" << std::endl;

    {
        IMateriaSource* book = new MateriaSource();
        book->learnMateria(new Ice());

        // book->learnMateria(new Ice());

        // book->learnMateria(new Ice());
        // book->learnMateria(new Cure());
        // book->learnMateria(new Ice());



        ICharacter*     jihyun = new Character("jihyun");

        AMateria*       temp;
        temp = book->createMateria("ice");
        jihyun->equip(temp);
        delete temp; temp = NULL;

        temp = book->createMateria("cur");
        jihyun->equip(temp);
        delete temp; temp = NULL;

        temp = book->createMateria("cure");
        jihyun->equip(temp);
        delete temp; temp = NULL;

        temp = book->createMateria("cure");
        jihyun->equip(temp);
        delete temp; temp = NULL;

        temp = book->createMateria("cure");
        jihyun->equip(temp);
        delete temp; temp = NULL;

        jihyun->unequip(0);


        ICharacter*     babo = new Character("babo");

        jihyun->use(0, *babo);
        jihyun->use(1, *babo);

        delete babo; babo = NULL;
        delete jihyun; jihyun = NULL;
        delete book; book = NULL;
    }

    return 0;
}
