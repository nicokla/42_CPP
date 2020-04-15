#ifndef KOALASTEROID_HPP
#define KOALASTEROID_HPP

#include "IAsteroid.hpp"

class Comet: public IAsteroid
{
    public:
        Comet();
        virtual ~Comet();
        Comet(const Comet &c);
        Comet &operator=(const Comet &c);

        std::string beMined(DeepCoreMiner *miner) const;
        std::string beMined(StripMiner *miner) const;
        std::string getName() const;
};

#endif
