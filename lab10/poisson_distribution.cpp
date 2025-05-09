#include "poisson_distribution.h"
#include <cmath>

Poisson_distribution::Poisson_distribution(unsigned int seed, float lb) : BG(seed), lambda(lb){}
Poisson_distribution::~Poisson_distribution() = default;
unsigned int Poisson_distribution::generate(){
    unsigned int m = 0;
    float S = 0.0f;
    while(true){
        float some = BG.generate();
        S += log(some);
        if(S < -lambda){
            return m;
        }
        else {
            ++m;
        }
    }
    return -1;
}
