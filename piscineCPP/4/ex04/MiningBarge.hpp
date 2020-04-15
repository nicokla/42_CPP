#ifndef MININGBARGE_HPP
#define MININGBARGE_HPP

#include "IMiningLaser.hpp"

class MiningBarge
{
    private:
        IMiningLaser *lasers[4];

    public:
        MiningBarge();
        ~MiningBarge();
        MiningBarge(const MiningBarge &c);
        MiningBarge &operator=(const MiningBarge &c);

        void equip(IMiningLaser *laser);
        void mine(IAsteroid *asteroid) const;
};

#endif
