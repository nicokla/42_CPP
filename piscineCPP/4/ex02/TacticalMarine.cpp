#include "TacticalMarine.hpp"

TacticalMarine::TacticalMarine() {
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::TacticalMarine(TacticalMarine const &obj) {
	*this = obj;
	std::cout << "Tactical Marine ready for battle" << std::endl;
}

TacticalMarine::~TacticalMarine() {
	std::cout << "Aaargh ..." << std::endl;
}

TacticalMarine &TacticalMarine::operator=(TacticalMarine const &r) {
	(void)r;
	return (*this);
}

ISpaceMarine *TacticalMarine::clone() const {
	ISpaceMarine	*ret = new TacticalMarine(*this);
	return (ret);
}

void TacticalMarine::battleCry() const {
	std::cout << "For the holy PLOT !" << std::endl;
}

void TacticalMarine::rangedAttack() const {
	std::cout << "* attacks with bolter *" << std::endl;
}

void TacticalMarine::meleeAttack() const {
	std::cout << "* attacks with chainsword *" << std::endl;
}
