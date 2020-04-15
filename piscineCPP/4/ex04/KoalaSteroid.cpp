#include "KoalaSteroid.hpp"

Comet::Comet() {}

Comet::~Comet() {}

Comet::Comet(const Comet &c) {
    (void)c;
}

Comet &Comet::operator=(const Comet &c) {
    (void)c;
    return *this;
}

std::string Comet::beMined(DeepCoreMiner *miner) const {
    (void)miner;
    return "Meium";
}

std::string Comet::beMined(StripMiner *miner) const {
    (void)miner;
    return "Tartarite";
}

std::string Comet::getName() const {
    return "Comet";
}
