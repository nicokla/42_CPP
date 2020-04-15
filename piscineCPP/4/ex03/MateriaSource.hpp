#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        AMateria* materias[4];

    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource(const MateriaSource &c);
        MateriaSource &operator=(const MateriaSource &c);

        virtual void learnMateria(AMateria *materia);
        virtual AMateria *createMateria(const std::string &type);
};

#endif
