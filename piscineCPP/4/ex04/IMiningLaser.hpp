#ifndef IMININGLASER
#define IMININGLASER

#include "IAsteroid.hpp"

class IMiningLaser
{
    public:
        virtual ~IMiningLaser() {}
        virtual void mine(IAsteroid *asteroid) = 0;
};

#endif
