#include "StripMiner.hpp"
#include "IAsteroid.hpp"
#include <iostream>

StripMiner::StripMiner() {}

StripMiner::~StripMiner() {}

StripMiner::StripMiner(const StripMiner &c) {
    (void)c;
}

StripMiner &StripMiner::operator=(StripMiner &c) {
    (void)c;
    return *this;
}

void StripMiner::mine(IAsteroid *asteroid) {
    std::cout << "* strip mining ... got "
        << asteroid->beMined(this) << " ! *" << std::endl;
}
