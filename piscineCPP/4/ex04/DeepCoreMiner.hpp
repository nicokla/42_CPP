#ifndef DEEPCOREMINER_HPP
#define DEEPCOREMINER_HPP

#include "IMiningLaser.hpp"

class IAsteroid;
class IMiningLaser;

class DeepCoreMiner: public IMiningLaser
{
    public:
        DeepCoreMiner();
        virtual ~DeepCoreMiner();
        DeepCoreMiner(const DeepCoreMiner &c);
        DeepCoreMiner &operator=(DeepCoreMiner &c);

        virtual void mine(IAsteroid *asteroid);
};

#endif
