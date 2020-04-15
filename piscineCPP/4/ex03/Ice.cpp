#include "Ice.hpp"
#include <iostream>

Ice::Ice(): AMateria("ice") {}

Ice::~Ice() {}

Ice::Ice(const Ice &c): AMateria("ice") {
    (void)c;
}

Ice &Ice::operator=(const Ice &c) {
    (void)c;
    return *this;
}

Ice *Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter &target) {
    AMateria::use(target);
    std::cout << "* shoots an ice bolt at "
        << target.getName() << " *" << std::endl;
}
