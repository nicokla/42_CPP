#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
    private:
        std::string name;
        AMateria* inventory[4];

        Character();

    public:
        Character(const std::string name);
        virtual ~Character();
        Character(const Character &c);
        Character &operator=(const Character&c);

        virtual const std::string &getName() const;
        virtual void equip(AMateria *m);
        virtual void unequip(int i);
        virtual void use(int i, ICharacter &target);
};

#endif
