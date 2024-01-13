#include "./Character.hpp"

/* OCCF: constructor */
Character::Character()
    : _name("(noname)"), _invCount(0), _floorIndex(0)
{
    // std::cout << "🐰 [Character]: default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

Character::Character(const std::string& name)
    : _name(name), _invCount(0), _floorIndex(0)
{
    for (int i = 0; i < 4; i++)
        _inventory[i] = NULL;
}

/* OCCF: copy constructor */
Character::Character(const Character& origin)
    : _name(origin._name), _invCount(origin._invCount)
{
    // std::cout << "🐰 [Character]: default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (origin._inventory[i] == NULL)
            continue;
        delete this->_inventory[i];
        this->_inventory[i] = origin._inventory[i]->clone();
    }
}

/* OCCF: copy assignment operator overloading */
Character& Character::operator=(const Character& origin)
{
    // std::cout << "🐰 [Character]: default constructor" << std::endl;
    if (this != &origin)
    {
        this->_name = origin._name;
        this->_invCount = origin._invCount;
        for (int i = 0; i < 4; i++)
        {
            if (origin._inventory[i] == NULL)
                continue ;
            delete this->_inventory[i];
            this->_inventory[i] = origin._inventory[i]->clone();
        }
    }
    return *this;
}

/* OCCF: Destructor */
Character::~Character()
{
    // std::cout << "🐰 [Character]: destructor" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_inventory[i] != NULL)
            delete this->_inventory[i];
    for (int i = 0; i < this->_floorIndex; i++)
        delete this->_floor[i];
}

/* member functions */
const std::string& Character::getName(void) const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (this->_invCount == 4)
    {
        std::cout << "🐰 [FULL]: cannot equip the type(" << m->getType() << ") 🥲" << std::endl;
        return ;
    }
    this->_invCount++;
    for (int i = 0; i < 4; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            _inventory[i] = m->clone();
            return ;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx >= 4)
    {
        std::cout << "🐰 [WRONG]: index does not exist 🥲" << std::endl;
        return ;
    }
    this->_floor[this->_floorIndex] = this->_inventory[idx];
    this->_floorIndex++;
    this->_inventory[idx] = NULL;
    this->_invCount--;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 4 || idx < 0 || this->_inventory[idx] == NULL)
    {
        std::cout << "🐰 [NO]: cannot use inventory(" << idx << ") 🥲" << std::endl;
        return ;
    }
    // std::cout << "🐰 " << this->_name << "\t";
    this->_inventory[idx]->use(target);
}
