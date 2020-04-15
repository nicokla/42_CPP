#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        materias[i] = NULL;
}

MateriaSource::~MateriaSource() {
    for (int i = 0; i < 4; i++)
        delete materias[i];
}

MateriaSource::MateriaSource(const MateriaSource &c) {
    for (int i = 0; i < 4; i++)
        materias[i] = c.materias[i];
}

MateriaSource &MateriaSource::operator=(const MateriaSource &c) {
    for (int i = 0; i < 4; i++)
        delete materias[i];
    for (int i = 0; i < 4; i++)
        materias[i] = c.materias[i];
    return *this;
}

void MateriaSource::learnMateria(AMateria *materia) {
    if (materias[3])
        return;
    int i = 0;
    while (materias[i])
        i++;
    materias[i] = materia;
}

AMateria *MateriaSource::createMateria(const std::string &type) {
    for (int i = 0; i < 4; i++)
        if (materias[i] && materias[i]->getType() == type)
            return materias[i]->clone();
    return NULL;
}
