#ifndef ASTEROKREOG_HPP
#define ASTEROKREOG_HPP

#include "IAsteroid.hpp"

class Asteroid: public IAsteroid
{
    public:
        Asteroid();
        virtual ~Asteroid();
        Asteroid(const Asteroid &c);
        Asteroid &operator=(const Asteroid &c);

		std::string beMined(DeepCoreMiner *miner) const;
		std::string beMined(StripMiner *miner) const;
		std::string getName() const;
};

#endif
