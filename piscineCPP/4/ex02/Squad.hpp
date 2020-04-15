#ifndef SQUAD_HPP
#define SQUAD_HPP

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad : public ISquad {
public:
	Squad();
	Squad(const Squad &src);
	~Squad();
	Squad   &operator= (const Squad &rhs);

	virtual int				push(ISpaceMarine *marine);
	virtual int				getCount(void) const;
	virtual ISpaceMarine	*getUnit(int n) const;

private:
	typedef struct MarinesList_ {
		ISpaceMarine *marine;
		struct MarinesList_ *next;
	} MarinesList;

	int				numberOfMarines;
	MarinesList		*marinesList;

	void			copyUnits(const Squad &src);
	void			destroyUnits();
	bool			marineAlreadyIn(ISpaceMarine *marine);
};

#endif
