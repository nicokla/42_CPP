#ifndef STRIPMINER_HPP
#define STRIPMINER_HPP

#include "IMiningLaser.hpp"

class StripMiner: public IMiningLaser
{
    public:
        StripMiner();
        virtual ~StripMiner();
        StripMiner(const StripMiner &c);
        StripMiner &operator=(StripMiner &c);

        virtual void mine(IAsteroid *asteroid);
};

#endif
