#include "./MateriaSource.hpp"

/* OCCF: constructor */
MateriaSource::MateriaSource()
    : _tempIndex(0)
{
    // std::cout << "📕 [MateriaSource]: default constructor" << std::endl;
    for (int i = 0; i < 4; i++)
        this->_templates[i] = NULL;
}

/* OCCF: copy constructor */
MateriaSource::MateriaSource(const MateriaSource& origin)
    : _tempIndex(origin._tempIndex)
{
    // std::cout << "📕 [MateriaSource]: copy constructor" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        if (origin._templates[i] == NULL)
            continue ;
        delete this->_templates[i];
        this->_templates[i] = origin._templates[i]->clone();
    }
}

/* OCCF: copy assignment operator overloading */
MateriaSource& MateriaSource::operator=(const MateriaSource& origin)
{
    // std::cout << "📕 [MateriaSource]: copy assignment operator overloading" << std::endl;
    if (this != &origin)
    {
        this->_tempIndex = origin._tempIndex;
        for (int i = 0; i < 4; i++)
        {
            if (origin._templates[i] == NULL)
                continue ;
            delete this->_templates[i];
            this->_templates[i] = origin._templates[i]->clone();
        }
    }
    return *this;
}

/* OCCF: Destructor */
MateriaSource::~MateriaSource()
{
    // std::cout << "📕 [MateriaSource]: copy assignment operator overloading" << std::endl;
    for (int i = 0; i < 4; i++)
        if (this->_templates[i] != NULL)
            delete this->_templates[i];
}

/* member functions */
void MateriaSource::learnMateria(AMateria* learn)
{
    if (this->_tempIndex == 4)
    {
        std::cout << "📕 [FULL]: cannot learn type '" << learn->getType() << "' 🥲" << std::endl;
        delete learn;
        return ;
    }
    this->_templates[this->_tempIndex] = learn;
    this->_tempIndex++;
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
    for (int i = 0; i < this->_tempIndex; i++)
        if (this->_templates[i]->getType() == type)
            return this->_templates[i]->clone();
    std::cout << "📕 [ERROR]: type'" << type << "' is not exist ❌" << std::endl;
    return NULL;
}
