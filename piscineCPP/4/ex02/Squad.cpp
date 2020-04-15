#include "Squad.hpp"

Squad::Squad() {
	this->numberOfMarines = 0;
	this->marinesList = NULL;
}

Squad::Squad(const Squad &src) {
	this->copyUnits(src);
	this->numberOfMarines = src.numberOfMarines;
}

Squad::~Squad() {
	this->destroyUnits();
}

Squad &Squad::operator= (const Squad &rhs) {
	if (this != &rhs) {
		this->destroyUnits();
		this->copyUnits(rhs);
		this->numberOfMarines = rhs.numberOfMarines;
	}
	return (*this);
}

int Squad::push(ISpaceMarine *marine) {
	MarinesList  *tmp;
	if (marine != NULL && !(this->marineAlreadyIn(marine))) {
		tmp = this->marinesList;
		if (this->marinesList != NULL) {
			while (tmp->next) {
				tmp = tmp->next;
			}
			tmp->next = new MarinesList;
			tmp->next->marine = marine;
			tmp->next->next = NULL;
		} else {
			this->marinesList = new MarinesList;
			this->marinesList->marine = marine;
			this->marinesList->next = NULL;
		}
		this->numberOfMarines += 1;
	}
	return (this->numberOfMarines);
}

int Squad::getCount(void) const {
	return (this->numberOfMarines);
}

ISpaceMarine *Squad::getUnit(int n) const {
	MarinesList  *tmp;

	tmp = this->marinesList;
	if (n < 0 || n >= this->numberOfMarines)
		return (NULL);
	while (n--) {
		tmp = tmp->next;
	}
	return (tmp->marine);
}

void Squad::copyUnits(const Squad &src) {
	MarinesList  *tmp;
	tmp = src.marinesList;
	while (tmp != NULL) {
		push(tmp->marine->clone());
		tmp = tmp->next;
	}
}

void Squad::destroyUnits() {
	MarinesList  *tmp, *tmp2;
	tmp = this->marinesList;
	while (tmp != NULL) {
		delete tmp->marine;
		tmp2 = tmp->next;
		delete tmp;
		tmp = tmp2;
	}
}

bool Squad::marineAlreadyIn(ISpaceMarine *marine) {
	MarinesList  *tmp = this->marinesList;
	while (tmp != NULL){
		if (tmp->marine == marine)
			return true;
		tmp = tmp->next;
	}
	return false;
}
