#ifndef NORM_DIS_H
#define NORM_DIS_H

#include "mtgen.h"
#include <vector>
#include <QString>
#include <QStringList>

class MTG;

class Norm_distr{
public:
    Norm_distr(unsigned int n,float mn, float var, unsigned int sd);
    ~Norm_distr();
    void generate_N();
    std::vector<unsigned int> generate_statistic();
    void change_seed(unsigned int sd);
    std::vector<float> get_norm_values();
    std::vector<unsigned int> generate_statistic(QStringList* categories);
    float get_emp_mean();
    float get_emp_var();
    float get_chi_squared();
private:
    unsigned int seed, N, k;
    float mean, variance, emp_mean;
    std::vector<float> norm_values;
    MTG gen;
    float generate();
    float chi_squared;

};

#endif // NORM_DIS_H
