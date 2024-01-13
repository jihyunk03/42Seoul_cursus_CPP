#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "./IMateriaSource.hpp"
# include "./Ice.hpp"
# include "./Cure.hpp"

class MateriaSource
    : public IMateriaSource
{
    private:
        int         _tempIndex;
        AMateria    *_templates[4];

    public:
        /* OCCF */
        MateriaSource();
        MateriaSource(const MateriaSource& origin);
        MateriaSource&      operator=(const MateriaSource& origin);
        virtual             ~MateriaSource();

        /* member functions */
        virtual void        learnMateria(AMateria* learn);
        virtual AMateria*   createMateria(const std::string& type);
};

#endif
