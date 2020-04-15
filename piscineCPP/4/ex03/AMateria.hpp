#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>

class ICharacter;

class AMateria
{
    private:
        std::string type;
        unsigned int xp;

        AMateria();

    public:
        AMateria(const std::string &type);
        virtual ~AMateria();
        AMateria(const AMateria &other);
        AMateria &operator=(const AMateria &other);

        const std::string &getType() const;
        unsigned int getXP() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter &target);
};

#endif
