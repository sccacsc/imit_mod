#ifndef POISSON_DISTRIBUTION_H
#define POISSON_DISTRIBUTION_H

#include "mtgen.h"

class Poisson_distribution{
public:
    Poisson_distribution(unsigned int seed, float lb);
    ~Poisson_distribution();
    unsigned int generate();

private:
    MTG BG;
    float lambda;
};

#endif // POISSON_DISTRIBUTION_H
