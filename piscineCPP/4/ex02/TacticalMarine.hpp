#ifndef TACTICALMARINE_HPP
#define TACTICALMARINE_HPP

#include <iostream>
#include <string>
#include "ISpaceMarine.hpp"

class	TacticalMarine : public ISpaceMarine {
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const &obj);
		virtual ~TacticalMarine();
		TacticalMarine &operator=(TacticalMarine const &r);

		ISpaceMarine*	clone() const;
		void			battleCry() const;
		void			rangedAttack() const;
		void			meleeAttack() const;
};

#endif