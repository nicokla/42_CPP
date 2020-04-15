#include "Cure.hpp"
#include <iostream>

Cure::Cure(): AMateria("cure") {}

Cure::~Cure() {}

Cure::Cure(const Cure &c): AMateria("cure") {
    (void)c;
}

Cure &Cure::operator=(const Cure &c) {
    (void)c;
    return *this;
}

Cure *Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter &target) {
    AMateria::use(target);
    std::cout << "* heals " << target.getName()
        << "'s wounds *" << std::endl;
}
