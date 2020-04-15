#include "MiningBarge.hpp"

MiningBarge::MiningBarge() {
    for (int i = 0; i < 4; i++)
        lasers[i] = NULL;
}

MiningBarge::~MiningBarge() {
    for (int i = 0; i < 4; i++)
        delete lasers[i];
}

MiningBarge::MiningBarge(const MiningBarge &c) {
    for (int i = 0; i < 4; i++)
        lasers[i] = c.lasers[i];
}

MiningBarge &MiningBarge::operator=(const MiningBarge &c) {
    for (int i = 0; i < 4; i++)
        delete lasers[i];
    for (int i = 0; i < 4; i++)
        lasers[i] = c.lasers[i];
    return *this;
}

void MiningBarge::equip(IMiningLaser *laser) {
    int i = 0;
    while (lasers[i] && lasers[i] != laser && i < 4)
        i++;
	if (i < 4)
    	lasers[i] = laser;
}

void MiningBarge::mine(IAsteroid *asteroid) const {
    for (int i = 0; i < 4; i++)
        if (lasers[i])
            lasers[i]->mine(asteroid);
}
