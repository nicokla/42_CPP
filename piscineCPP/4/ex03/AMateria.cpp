#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::AMateria(const std::string &type):
    type(type), xp(0) {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria &other):
    type(other.type), xp(other.xp) {}

AMateria &AMateria::operator=(const AMateria &other) {
    type = other.type;
    xp = other.xp;
    return *this;
}

const std::string &AMateria::getType() const {
    return type;
}

void AMateria::use(ICharacter &target) {
    (void)target;
    xp += 10;
}
