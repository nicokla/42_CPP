#include "DeepCoreMiner.hpp"
#include "IAsteroid.hpp"
#include <iostream>

DeepCoreMiner::DeepCoreMiner() {}

DeepCoreMiner::~DeepCoreMiner() {}

DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner &c) {
    (void)c;
}

DeepCoreMiner &DeepCoreMiner::operator=(DeepCoreMiner &c) {
    (void)c;
    return *this;
}

void DeepCoreMiner::mine(IAsteroid *asteroid) {
    std::cout << "* mining deep ... got "
        << asteroid->beMined(this) << " ! *" << std::endl;
}
