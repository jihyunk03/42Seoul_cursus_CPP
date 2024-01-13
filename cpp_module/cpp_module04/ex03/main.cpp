#include "./MateriaSource.hpp"
#include "./Character.hpp"

static void _check_leaks(void);

int main(void)
{
    atexit(_check_leaks);
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

    return 0;
}

static void _check_leaks(void)
{
    system("leaks Materias");
}
